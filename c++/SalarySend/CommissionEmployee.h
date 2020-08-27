#ifndef COMMISSIONEMPLOYEE_H
#define COMMISSIONEMPLOYEE_H

#include "Person.h"

class CommissionEmployee: virtual public Person
{
    public:
        CommissionEmployee(string name,string number,int age, int commission,int commissionSalary);
        virtual ~CommissionEmployee();
        void display();
        void setSalary(int);
        int  getCommissionSalary();
        int  getCommission();
        void  setCommissionSalary(int salary);
    protected:
    private:
        int m_commission;
        int m_commissionSalary;

};

#endif // COMMISSIONEMPLOYEE_H
