#include "basepluscommissionemployee.h"

BasePlusCommissionEmployee::BasePlusCommissionEmployee(
             const MyString &id, const MyString &name, const MyString &phone,
             double weeklySalary, double grossSales, double commissionRate)
             :Employee(id, Employee::WorkType_BasePlusCommissionEmployee, name, phone),
             SalariedEmployee(id, name, phone, weeklySalary),
             CommissionEmployee(id, name, phone, grossSales, commissionRate)

{
}

double BasePlusCommissionEmployee::earnings()const
{
    return  getWeeklySalary() + getGrossSales()
            + getGrossSales() * getCommissionRate();
}
void BasePlusCommissionEmployee::display()const
{
    cout << "BasePlusCommissionEmployee::ID: " << getID() << endl;
    cout << "BasePlusCommissionEmployee::Type: " << getWorkType() << endl;
    cout << "BasePlusCommissionEmployee::Name: " << getName() << endl;
    cout << "BasePlusCommissionEmployee::Phone: " << getPhone() <<endl;
    cout << "BasePlusCommissionEmployee::WeeklySalary: " << getWeeklySalary() << endl;
    cout << "BasePlusCommissionEmployee::GrossSales: " << getGrossSales() << endl;
    cout << "BasePlusCommissionEmployee::CommissionRate: " << getCommissionRate() << endl;
}
