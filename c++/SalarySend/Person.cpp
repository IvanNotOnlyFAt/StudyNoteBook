#include "Person.h"

Person::Person()
{
    m_name = "NULL";
    m_employeeNumber = "000";
    m_age = 0;
}

Person::Person(string name,string number,int age)
{
    m_name = name;
    m_employeeNumber = number;
    m_age = age;
}

void Person::operator=(const Person &p)
{
    m_name = p.getName();
    m_employeeNumber = p.getNumber();
    m_age = p.getAge();
}

Person::~Person()
{

}

string Person::getName() const
{
    return m_name;
}

void Person::setName(string name)
{
    m_name = name;
}

string Person::getNumber() const
{
    return m_employeeNumber;
}

void Person::setNumber(string number)
{
    m_employeeNumber = number;
}

int Person::getAge() const
{
    return m_age;
}

void Person::display()
{
        cout << "------------------------" << endl;
        cout << "Name:" << m_name << endl;
        cout << "Employee ID:" << m_employeeNumber << endl;
        cout << "Age:" << m_age << endl;
        cout << "------------------------" << endl;

}

void Person::setSalary(int salary)
{

}
