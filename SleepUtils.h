// Copyright (c) 2017 Ronald Bondy
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef FORTUNA_LINUX_SLEEPUTILS_H
#define FORTUNA_LINUX_SLEEPUTILS_H

// Static class that contains helper functions for sleep functions
class SleepUtils {
public:
    // Sleep for the specified number of milliseconds
    // Returns result from nanosleep
    static int sleep_ms(int milliseconds);

public:
    // disallow the default constructor
    SleepUtils()=delete;

    // disallow copying
    SleepUtils& operator=(const SleepUtils&)=delete;
    SleepUtils(const SleepUtils&)=delete;

    // disallow moving
    SleepUtils& operator=(SleepUtils&& )=delete;
    SleepUtils(SleepUtils&&)=delete;

    ~SleepUtils()=delete;
};


#endif //FORTUNA_LINUX_SLEEPUTILS_H
