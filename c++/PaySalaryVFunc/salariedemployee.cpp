#include "salariedemployee.h"

SalariedEmployee::SalariedEmployee(const MyString &id,
              const MyString &name,const MyString &phone,
              double weeklySalary)
             :Employee(id, Employee::WorkType_SalariedEmployee ,name, phone)
{
    m_weeklySalary = weeklySalary;
}

void SalariedEmployee::setWeeklySalary(double weeklySalary)
{
    m_weeklySalary = weeklySalary;
}
double SalariedEmployee::getWeeklySalary() const
{
    return m_weeklySalary;
}

double SalariedEmployee::earnings()const
{
    return m_weeklySalary;
}
void SalariedEmployee::display()const
{
    cout << "SalariedEmployee::ID: " << getID() << endl;
    cout << "SalariedEmployee::Type: " << getWorkType() << endl;
    cout << "SalariedEmployee::Name: " << getName() << endl;
    cout << "SalariedEmployee::Phone: " << getPhone() <<endl;
    cout << "SalariedEmployee::WeeklySalary: " << m_weeklySalary << endl;
}
