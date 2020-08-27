#include "HourEmployee.h"


HourEmployee::HourEmployee(string name,string number,int age,int hour,int hourSalary):Person(name,number,age)
{
    m_hour = hour;
    m_hourSalary = hourSalary;
}

HourEmployee::~HourEmployee()
{
    //dtor
}
int HourEmployee::getHour(void)
{
    return m_hour;
}
int HourEmployee::getHourSalary(void)
{
    return m_hourSalary;
}
void HourEmployee::display()
{
        cout << "------------------------" << endl;
        cout << "|      HourEmployee    |" << endl;
        cout << "------------------------" << endl;
        cout << "Name: " << this->getName() << endl;
        cout << "Employee ID: " << this->getNumber() << endl;
        cout << "Age: " << this->getAge() << endl;
        cout << "HourSalary: " << m_hourSalary << endl;
        cout << "Hour: " << m_hour << endl;
        cout << "Total Salary: " << m_hour*m_hourSalary << endl;
        cout << "------------------------" << endl;
}

void HourEmployee::setSalary(int salary)
{
    m_hourSalary = salary;
}
