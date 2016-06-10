#include <iostream>
#include <stdio.h>

#include "ruminations.h"

using namespace std;

int Test::count = 0;

Test::Test()
{
    id = ++count;
    cout << "Test " << id << " default constructor." << endl;
}

Test::~Test()
{
    cout << "Test " << id << " destroyed" << endl;
}

Test::Test(const Test &t)
{
    id = ++count;
    cout << "Test " << id << " copied from " << t.id << endl;
}

Test&
Test::operator=(const Test &t)
{
    cout << "Test " << id << " assigned from " << t.id << endl;
    return *this;
}
