#include "time_meter_impl.h"

TimeMeter::Impl::Impl(unsigned count) : stamps(count, 0)
{
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start);
}

int64_t TimeMeter::Impl::elapsedNs() const
{
    LARGE_INTEGER now;
    QueryPerformanceCounter(&now);
    int64_t ticks = now.QuadPart - start.QuadPart;
    return (ticks / freq.QuadPart) * 1000000000LL + (ticks % freq.QuadPart) * 1000000000LL / freq.QuadPart;
}
