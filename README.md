# Fortuna-Linux
This is an implementation of the Fortuna PRNG for Linux using native C++11 threads.

In my design, each pool and each source execute on their own thread.  This is done so that the ordering of the source bytes added to each pool is made more difficult to predict.  Each pool is protected by a Mutex, and the operating system decides which Source thread adds data to the pool when multiple Sources are simultaneously adding source bytes to a given pool.  This use of these threads will slow down the CSPRNG and increase the compute load, but this is a trade off to provide greater security and make it more difficult for an attacker to reverse engineer or duplicate the results of the CSPRNG.

Also, in my implementation the data from each Source is encrypted using CTR mode with a unique key before being sent to the Pools.  Encryption is a fast operation and encrypting the data before sending the pools provides an extra layer of protection if an attacker is able to compromise one of the data sources.  The encryption key is updated periodically.

In the Fortuna algorithm from Schneier and Ferguson, n bytes of data from a Source are sent to a Pool.  In my implementation, individual bytes are spread over the pools (after the bytes are encrypted to add an extra layer of security).

Sources used in my implementation include \dev\random and also many different operating system operations that are timed using the rdtsc() counter.  Using rdtsc() makes it very difficult for an attacker to reproduce the results of the CSPRNG.
