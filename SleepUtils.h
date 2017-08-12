// Copyright (c) 2017 Ronald Bondy
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef FORTUNA_LINUX_SLEEPUTILS_H
#define FORTUNA_LINUX_SLEEPUTILS_H

namespace SleepUtils {

    // Sleep for the specified number of milliseconds
    // Returns result from nanosleep
    int sleep_ms(int milliseconds);
}


#endif //FORTUNA_LINUX_SLEEPUTILS_H
