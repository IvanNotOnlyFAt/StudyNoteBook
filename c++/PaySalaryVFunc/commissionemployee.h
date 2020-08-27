#ifndef __COMMISSION_EMPLOYEE_H
#define __COMMISSION_EMPLOYEE_H

#include <iostream>
#include "employee.h"

using namespace std;
class CommissionEmployee:virtual public Employee
{
public:
    CommissionEmployee(const MyString &id = "123456",
            const MyString &name = "xiaoming",
             const MyString &phone = "13356564545",
             double grossSales = 1000,
             double commissionRate = 0.35);

    void setGrossSales(double grossSales);
    double getGrossSales() const;
    void setCommissionRate(double commissionRate);
    double getCommissionRate() const;

    double earnings()const;
    void display()const;
private:
    double m_grossSales;
    double m_commissionRate;
};

#endif // __COMMISSION_EMPLOYEE_H

