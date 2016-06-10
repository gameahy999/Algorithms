#include <stdio.h>

#include "WinTimer.h"

namespace util
{

WinTimer::WinTimer(): timerFreq(0),
                      c1(0), c2(0)
{
    QueryPerformanceFrequency(&largeInteger);
    timerFreq = largeInteger.QuadPart;
}

WinTimer::~WinTimer()
{

}

void
WinTimer::start()
{
    QueryPerformanceCounter(&largeInteger);
    c1 = largeInteger.QuadPart;
}

void
WinTimer::stop()
{
    QueryPerformanceCounter(&largeInteger);
    c2 = largeInteger.QuadPart;
}

void
WinTimer::printResult()
{
    printf("The process spends: %lf ms.\n",
           (c2-c1) * 1000 / timerFreq);
}

void
WinTimer::printResult(const char *title)
{
    printf("%s spends: %lf ms.\n",
           title,
           (c2-c1) * 1000 / timerFreq);
}

}
