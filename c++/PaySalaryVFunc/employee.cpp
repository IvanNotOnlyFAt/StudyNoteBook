#include "employee.h"

Employee::Employee(const MyString &id, WorkType workType,
                   const MyString &name, const MyString &phone)
{
    m_id = id;
    m_workType = workType;
    m_name = name;
    m_phone = phone;
}

void Employee::setWorkType(WorkType workType)
{
    m_workType = workType;
}

Employee::WorkType Employee::getWorkType() const
{
    return m_workType;
}

void Employee::setID(const MyString &id)
{
    m_id = id;
}
const MyString &Employee::getID() const
{
    return m_id;
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

//double Employee::earnings() const
//{
//    return 0;
//}
//
//void Employee::display()const
//{
//    cout << "Employee::ID: " << m_id << endl;
//    cout << "Employee::Type: " << m_workType << endl;
//    cout << "Employee::Name: " << m_name << endl;
//    cout << "Employee::Phone: " << m_phone <<endl;
//}
