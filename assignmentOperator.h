#ifndef _ASSIGNMENT_OPERATOR_H_
#define _ASSIGNMENT_OPERATOR_H_

class CMyString
{
public:
    CMyString(const char* pData = NULL);
    CMyString(const CMyString& str);
    ~CMyString(void);

    CMyString& operator = (const CMyString& str);

    void Print();

private:
    char* m_pData;
};

void test_assignmentOperator();

#endif