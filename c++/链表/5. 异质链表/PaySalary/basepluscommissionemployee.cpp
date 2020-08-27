#include "basepluscommissionemployee.h"

BasePlusCommissionEmployee::BasePlusCommissionEmployee(
             const MyString &name,
             const MyString &phone,
             double weeklySalary,
             double grossSales,
             double commissionRate)
             :SalariedEmployee(name, phone, weeklySalary),
             CommissionEmployee(name, phone, grossSales, commissionRate),
             Employee(name, phone)
{

}

double BasePlusCommissionEmployee::earnings()const
{
    return  getWeeklySalary() + getGrossSales()
            + getGrossSales() * getCommissionRate();
}
void BasePlusCommissionEmployee::display()const
{
    cout << "BasePlusCommissionEmployee::Name: " << getName() << endl;
    cout << "BasePlusCommissionEmployee::Phone: " << getPhone() <<endl;
    cout << "BasePlusCommissionEmployee::WeeklySalary: " << getWeeklySalary() << endl;
    cout << "BasePlusCommissionEmployee::GrossSales: " << getGrossSales() << endl;
    cout << "BasePlusCommissionEmployee::CommissionRate: " << getCommissionRate() << endl;
}
