#pragma once

#include "time_meter.h"
#include <vector>

#ifdef _WIN32
#include <windows.h>
#else
#include <ctime>
#endif

class TimeMeter::Impl
{
public:
    explicit Impl(unsigned count);

    int64_t elapsedNs() const;

    std::vector<int64_t> stamps;

private:
#ifdef _WIN32
    LARGE_INTEGER freq;
    LARGE_INTEGER start;
#else
    timespec start;
#endif
};
