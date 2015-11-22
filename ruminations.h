#ifndef _RUMINATIONS_H_
#define _RUMINATIONS_H_

class Test {
public:
    Test();
    ~Test();
    Test(const Test &);
    Test& operator=(const Test &);

private:
    static int count;
    int id;
};

#endif