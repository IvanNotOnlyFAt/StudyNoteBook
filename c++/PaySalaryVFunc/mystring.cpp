#include "mystring.h"
#include <string.h>

MyString::MyString()
{
    m_data = NULL;
    m_len = 0;
}
MyString::MyString(const char *str)
{
    m_len = strlen(str);
    m_data = new char[m_len+1];
    strcpy(m_data, str);

}
MyString::MyString(const MyString &str)
{
    m_len = strlen(str.m_data);
    m_data = new char[m_len+1];
    strcpy(m_data, str.m_data);
}
MyString::~MyString()
{
    if(m_data != NULL)
    {
        delete []m_data;
    }
}

const char *MyString::getData(void)
{
    return m_data;
}

MyString &MyString::operator=(const MyString &str)
{
    if(this == &str)
    {
        return *this;
    }

    if(m_data != NULL)
    {
        delete []m_data;
    }

    m_len = strlen(str.m_data);
    m_data = new char[m_len+1];
    strcpy(m_data, str.m_data);

    return *this;
}

void MyString::append(const char *str)
{
    m_len += strlen(str);
    char *temp = new char[m_len+1];
    strcpy(temp, m_data);
    strcat(temp, str);
    delete m_data;
    m_data = temp;
}

void MyString::disp(void) const
{
    cout << m_data << endl;
}

bool operator==(const MyString &str1, const MyString &str2)
{
    return strcmp(str1.m_data, str2.m_data);
}

ostream &operator<<(ostream &os, const MyString &str)
{
    return os << str.m_data;
}

