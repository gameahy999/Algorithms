#include "exception.h"

void test_exception()
{
    // throw std::exception("This is a test of c++ exception!");
    throw MyException();
}