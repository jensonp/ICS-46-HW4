/* C++ interface for program benchmark timer management. */
#ifndef TIMER_H
#define TIMER_H

#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>

// extern "C" int gettimeofday(timeval *tp, void *tzp);
// extern "C" int getrusage(int who, struct rusage *rusag);

class Timer
{
public:
    inline int start();
    inline int elapsedWallclockTime (double &);
    inline int elapsedUserTime (double &);
    inline int elapsedSystemTime (double &);
    inline int elapsedTime (double &wc, double &us, double &system);
    
private:
    rusage old_us_time;
    rusage new_us_time;
    timeval old_wc_time;
    timeval new_wc_time;
};


inline int
Timer::start()
{
    if (gettimeofday (&this->old_wc_time, nullptr) == -1
        || getrusage (RUSAGE_SELF, &this->old_us_time) == -1)
        return -1;
    else
        return 0;
}

inline int
Timer::elapsedWallclockTime (double &wc)
{
    if (gettimeofday (&this->new_wc_time, nullptr) == -1)
        return -1;
    wc = (this->new_wc_time.tv_sec - this->old_wc_time.tv_sec)
         + (this->new_wc_time.tv_usec - this->old_wc_time.tv_usec) / 1000000.0;
    return 0;
}

inline int
Timer::elapsedUserTime (double &ut)
{
    if (getrusage (RUSAGE_SELF, &this->new_us_time) == -1)
        return -1;

    ut = (this->new_us_time.ru_utime.tv_sec - this->old_us_time.ru_utime.tv_sec)
        + ((this->new_us_time.ru_utime.tv_usec
            - this->old_us_time.ru_utime.tv_usec) / 1000000.0);
    return 0;
}

inline int
Timer::elapsedSystemTime (double &st)
{
    if (getrusage (RUSAGE_SELF, &this->new_us_time) == -1)
        return -1;

    st = (this->new_us_time.ru_stime.tv_sec - this->old_us_time.ru_stime.tv_sec)
        + ((this->new_us_time.ru_stime.tv_usec
            - this->old_us_time.ru_stime.tv_usec) / 1000000.0);
    return 0;
}

inline int
Timer::elapsedTime (double &wallclock, double &user_time, double &system_time)
{
    if (this->elapsedWallclockTime (wallclock) == -1)
        return -1;
    else
        {
            if (getrusage (RUSAGE_SELF, &this->new_us_time) == -1)
        return -1;
            user_time = (this->new_us_time.ru_utime.tv_sec
                - this->old_us_time.ru_utime.tv_sec)
        + ((this->new_us_time.ru_utime.tv_usec
            - this->old_us_time.ru_utime.tv_usec) / 1000000.0);

            system_time = (this->new_us_time.ru_stime.tv_sec
                - this->old_us_time.ru_stime.tv_sec)
        + ((this->new_us_time.ru_stime.tv_usec
            - this->old_us_time.ru_stime.tv_usec) / 1000000.0);

            return 0;
        }

}
#endif
