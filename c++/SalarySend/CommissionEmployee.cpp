#include "CommissionEmployee.h"

CommissionEmployee::CommissionEmployee(string name,string number,int age,int commission,int commissionSalary):Person(name,number,age)
{
    m_commission = commission;
    m_commissionSalary = commissionSalary;
}

CommissionEmployee::~CommissionEmployee()
{
    //dtor
}
void CommissionEmployee::display()
{
        cout << "------------------------" << endl;
        cout << "|  CommissionEmployee  |" << endl;
        cout << "------------------------" << endl;
        cout << "Name: " << this->getName() << endl;
        cout << "Employee ID: " << this->getNumber() << endl;
        cout << "Age: " << this->getAge() << endl;
        cout << "Commission: " << m_commission << endl;
        cout << "CommissionSalary: " << m_commissionSalary << endl;
        cout << "Total Salary: " << m_commissionSalary*m_commission << endl;
        cout << "------------------------" << endl;
}

void CommissionEmployee::setSalary(int comissionSalary)
{
    m_commissionSalary = comissionSalary;
}

int  CommissionEmployee::getCommissionSalary()
{
    return m_commissionSalary;
}

int  CommissionEmployee::getCommission()
{
    return m_commission;
}

void  CommissionEmployee::setCommissionSalary(int salary)
{
     m_commissionSalary = salary;
}

