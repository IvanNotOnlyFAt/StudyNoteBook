#ifndef __SALARIED_EMPLOYEE_H
#define __SALARIED_EMPLOYEE_H

#include <iostream>
#include "employee.h"

using namespace std;
class SalariedEmployee:virtual public Employee
{
public:
    SalariedEmployee(const MyString &id = "123456",
            const MyString &name = "xiaoming",
             const MyString &phone = "13356564545",
             double weeklySalary = 1000);

    void setWeeklySalary(double weeklySalary);
    double getWeeklySalary() const;

    double earnings()const;
    void display()const;
private:
    double m_weeklySalary;
};

#endif // __SALARIED_EMPLOYEE_H
