# Fortuna-Linux
This is an implementation of the Fortuna Cryptograpically Secure PRNG for Linux using C++11 and pthreads.

The description of the Fortuna algorithm is found here:
https://www.amazon.com/Practical-Cryptography-Niels-Ferguson/dp/0471223573/ref=sr_1_11

In my design, each pool and each source execute on their own thread.  This is done so that the ordering of the source
bytes added to each pool is made more difficult to predict because the bytes from each source are interleaved
 with all the sources as they are added to the pools.

Each pool is protected by a Mutex, and the operating system decides which Source thread adds data to the pool
when multiple Sources are in contention with regard to adding source bytes to the same pool.

This use of these threads will slow down the CSPRNG and increase the compute load, but this is a
trade off to provide greater security and make it more difficult for an attacker to reverse engineer or duplicate the
results of the CSPRNG.

Also, in my implementation the data from each Source is encrypted using CTR mode with a unique key before being sent
to the Pools.  Encryption using a stream ciper is a fast operation and encrypting the data before sending the pools provides an extra
layer of protection if an attacker is able to compromise one of the data sources.
The encryption key is updated periodically.

In the Fortuna algorithm from Schneier and Ferguson, n bytes of data from a Source are sent to a Pool.
In my implementation, individual bytes are spread over the pools (after the bytes are encrypted to add an extra layer of security).
Suppose a source obtains 1024 bytes from /dev/urandom.  Individual bytes are distributed among the pools in a round
robin fashion.

Sources used in my implementation include /dev/random and also many different operating system operations that are timed
 using the rdtsc() counter.  Using rdtsc() makes it very difficult for an attacker to reproduce the results of the CSPRNG.

Cryptographic functions are performed using the Crypto++ library.