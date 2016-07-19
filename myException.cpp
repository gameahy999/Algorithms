#include <exception>
#include "myException.h"

void test_exception()
{
    // throw std::exception("This is a test of c++ exception!");
    throw MyException();
}

const char*
MyException::what()
{
    return "This is a test of my exception.";
}
