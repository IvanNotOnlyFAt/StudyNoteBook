#include "FixEmployee.h"

FixEmployee::FixEmployee(string name,string number,int age,int fixSalary):Person(name,number,age)
{
    m_fixSalary = fixSalary;
}
FixEmployee::~FixEmployee()
{
    //dtor
}

void FixEmployee::setSalary(int salary)
{
    m_fixSalary = salary;
}
void FixEmployee::display()
{
        cout << "------------------------" << endl;
        cout << "|      FixEmployee      |" << endl;
        cout << "------------------------" << endl;
        cout << "Name: " << this->getName() << endl;
        cout << "Employee ID: " << this->getNumber() << endl;
        cout << "Age: " << this->getAge() << endl;
        cout << "Total Salary: " << m_fixSalary << endl;
        cout << "------------------------" << endl;
}

int FixEmployee::getFixSalary(void)
{
    return m_fixSalary;
}

void FixEmployee::setFixSalary(int salary)
{
    m_fixSalary = salary;
}
