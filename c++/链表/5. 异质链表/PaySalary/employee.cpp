#include "employee.h"

Employee::Employee(const MyString &name,
                   const MyString &phone)
{
    m_name = name;
    m_phone = phone;
}

void Employee::setName(const MyString &name)
{
    m_name = name;
}
void Employee::setPhone(const MyString &phone)
{
    m_phone = phone;
}

const MyString &Employee::getName() const
{
    return m_name;
}
const MyString &Employee::getPhone() const
{
    return m_phone;
}

double Employee::earnings() const
{
    return 0;
}
void Employee::display()const
{
    cout << "Employee::Name: " << m_name << endl;
    cout << "Employee::Phone: " << m_phone <<endl;
}
