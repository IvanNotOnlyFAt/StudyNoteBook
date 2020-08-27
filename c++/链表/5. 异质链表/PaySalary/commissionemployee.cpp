#include "commissionemployee.h"

CommissionEmployee::CommissionEmployee(const MyString &name,
             const MyString &phone,
             double grossSales,
             double commissionRate)
             :Employee(name, phone)
{
    m_grossSales = grossSales;
    m_commissionRate = commissionRate;
}

void CommissionEmployee::setGrossSales(double grossSales)
{
    m_grossSales = grossSales;
}
double CommissionEmployee::getGrossSales() const
{
    return m_grossSales;
}
void CommissionEmployee::setCommissionRate(double commissionRate)
{
    m_commissionRate = commissionRate;
}
double CommissionEmployee::getCommissionRate() const
{
    return m_commissionRate;
}

double CommissionEmployee::earnings()const
{
    return m_grossSales + m_grossSales * m_commissionRate;
}
void CommissionEmployee::display()const
{
    cout << "CommissionEmployee::Name: " << getName() << endl;
    cout << "CommissionEmployee::Phone: " << getPhone() <<endl;
    cout << "CommissionEmployee::GrossSales: " << m_grossSales << endl;
    cout << "CommissionEmployee::CommissionRate: " << m_commissionRate << endl;
}
