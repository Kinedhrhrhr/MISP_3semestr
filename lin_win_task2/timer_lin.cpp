#include "time_meter_impl.h"

TimeMeter::Impl::Impl(unsigned count) : stamps(count, 0)
{
    clock_gettime(CLOCK_MONOTONIC, &start);
}

int64_t TimeMeter::Impl::elapsedNs() const
{
    timespec now;
    clock_gettime(CLOCK_MONOTONIC, &now);
    return static_cast<int64_t>(now.tv_sec - start.tv_sec) * 1000000000LL + (now.tv_nsec - start.tv_nsec);
}
