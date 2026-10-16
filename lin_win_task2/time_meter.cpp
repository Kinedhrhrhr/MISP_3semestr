#include "time_meter_impl.h"

TimeMeter::TimeMeter(unsigned count) : pImpl(new Impl(count)) {}

TimeMeter::~TimeMeter() = default;

double TimeMeter::setTimeStamp(unsigned num)
{
    int64_t ns = pImpl->elapsedNs();
    pImpl->stamps.at(num) = ns;
    return ns / 1e9;
}

double TimeMeter::getSTimeStamp(unsigned num) const
{
    return pImpl->stamps.at(num) / 1e9;
}

int64_t TimeMeter::getMSTimeStamp(unsigned num) const
{
    return pImpl->stamps.at(num) / 1000000;
}

double TimeMeter::getSDiff(unsigned first, unsigned second) const
{
    return (pImpl->stamps.at(second) - pImpl->stamps.at(first)) / 1e9;
}

int64_t TimeMeter::getMSDiff(unsigned first, unsigned second) const
{
    return (pImpl->stamps.at(second) - pImpl->stamps.at(first)) / 1000000;
}

bool TimeMeter::isLess(unsigned first, unsigned second, int64_t expected) const
{
    return getMSDiff(first, second) < expected;
}

bool TimeMeter::isLess(unsigned num, int64_t expected) const
{
    return getMSTimeStamp(num) < expected;
}
