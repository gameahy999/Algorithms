#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

void test_exception();

class MyException : public std::exception
{
public:
    virtual const char *what();
};

#endif
