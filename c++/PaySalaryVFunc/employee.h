#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H

#include <iostream>
#include "mystring.h"

using namespace std;

class Employee
{
public:
    enum WorkType
    {
        WorkType_NONE = 0,
        WorkType_SalariedEmployee,
        WorkType_CommissionEmployee,
        WorkType_HourlyEmployee,
        WorkType_BasePlusCommissionEmployee
    };

    Employee(const MyString &id = "123456",
             WorkType workType = WorkType_NONE,
             const MyString &name = "xiaoming",
             const MyString &phone = "13356564545");

    void setID(const MyString &id);
    const MyString &getID() const;

    void setWorkType(WorkType workType);
    WorkType getWorkType() const;

    void setName(const MyString &name);
    void setPhone(const MyString &phone);

    const MyString &getName() const;
    const MyString &getPhone() const;

    virtual double earnings()const = 0;
    virtual void display() const = 0;

private:
    MyString m_id;
    WorkType m_workType;
    MyString m_name;
    MyString m_phone;
};

#endif // __EMPLOYEE_H
