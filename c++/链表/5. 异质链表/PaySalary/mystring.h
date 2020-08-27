#ifndef __MY_STRING_H
#define __MY_STRING_H

#include <iostream>
using namespace std;

class MyString
{
public:
    MyString();
    MyString(const char *str);
    MyString(const MyString &str);
    MyString &operator=(const MyString &str);
    ~MyString();

    friend ostream &operator<<(ostream &os, const MyString &str);

    const char *getData(void);

    void append(const char *str);
    void disp(void) const;

private:
    char *m_data;
    unsigned int m_len;
};

#endif // __MY_STRING_H
