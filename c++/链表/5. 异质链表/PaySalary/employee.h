#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H

#include <iostream>
#include "mystring.h"

using namespace std;

class Employee
{
public:
    Employee(const MyString &name = "xiaoming",
             const MyString &phone = "13356564545");

    void setName(const MyString &name);
    void setPhone(const MyString &phone);

    const MyString &getName() const;
    const MyString &getPhone() const;

    double earnings()const;
    void display()const;


private:
    MyString m_name;
    MyString m_phone;
};

#endif // __EMPLOYEE_H
