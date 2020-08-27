#ifndef __BASEPLUSCOMMISSION_EMPLOYEE_H
#define __BASEPLUSCOMMISSION_EMPLOYEE_H

#include <iostream>
#include "salariedemployee.h"
#include "commissionemployee.h"

using namespace std;
class BasePlusCommissionEmployee: public SalariedEmployee, public CommissionEmployee
{
public:
    BasePlusCommissionEmployee(const MyString &id = "123456",
             const MyString &name = "xiaoming",
             const MyString &phone = "13356564545",
             double weeklySalary = 1000,
             double grossSales = 1000,
             double commissionRate = 0.35);

    double earnings()const;
    void display()const;
};

#endif // __BASEPLUSCOMMISSION_EMPLOYEE_H

