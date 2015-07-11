#ifndef _WIN_TIMER_H_
#define _WIN_TIMER_H_

#include <Windows.h>

/*
 *------------------------------------------------------------------------------
 *
 * Implementations of timer on windows platform.
 * It's usually used to compare the performances of two or more algorithms.
 *
 * Sample code:
 *   util::WinTimer t = util::WinTimer();
 *   t.start();
 *   doSomethingBlaBla();
 *   t.stop();
 *   t.printResult();
 *
 *------------------------------------------------------------------------------
 */

namespace util
{

class WinTimer {
public:
    WinTimer();
    ~WinTimer();
    void start();
    void stop();
    void printResult();
    void printResult(const char *title);

private:
    LARGE_INTEGER largeInteger;
    double timerFreq;
    __int64 c1, c2;
};

}

#endif