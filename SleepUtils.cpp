//
// Created by ron on 06/08/17.
//

#include <ctime>
#include "SleepUtils.h"

namespace SleepUtils {

// Sleep for the specified number of milliseconds
// Adapted from : https://stackoverflow.com/questions/1157209/is-there-an-alternative-sleep-function-in-c-to-milliseconds
    int sleep_ms(int milliseconds) {
        struct timespec ts;
        ts.tv_sec = milliseconds / 1000;
        ts.tv_nsec = (milliseconds % 1000) * 1000000;
        int result = nanosleep(&ts, nullptr);
        return result;
    }

} // end namespace SleepUtils
