#include "PaidComissionEmployee.h"

PaidComissionEmployee::PaidComissionEmployee(string name,string number,int age,int baseSalary,int commission,int commissionSalary):
                            Person(name,number,age),FixEmployee(name,number,age,baseSalary),CommissionEmployee(name,number,age,commission,commissionSalary)
{
    //ctor
}

PaidComissionEmployee::~PaidComissionEmployee()
{
    //dtor
}


void PaidComissionEmployee::display()
{
        int m = this->getFixSalary();
        int n = this->getCommissionSalary();
        int i = this->getCommission();
        cout << "------------------------" << endl;
        cout << "|PaidCommissionEmployee |" << endl;
        cout << "------------------------" << endl;
        cout << "Name: " << this->getName() << endl;
        cout << "Employee ID: " << this->getNumber() << endl;
        cout << "Age: " << this->getAge() << endl;
        cout << "BaseSalary: " <<  this->getFixSalary() << endl;
        cout << "CommissionSalary: " <<   this->getCommissionSalary() << endl;
        cout << "Commission: " <<   this->getCommission() << endl;
        cout << "Total Salary: " << m+n*i << endl;
        cout << "------------------------" << endl;
}
void PaidComissionEmployee::setSalary(int Salary)
{
    this->setFixSalary(Salary);
}

void PaidComissionEmployee::setCommissionSalary(int Salary)
{
    this->setCommissionSalary(Salary);
}
