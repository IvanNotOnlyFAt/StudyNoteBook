#ifndef PAIDCOMISSIONEMPLOYEE_H
#define PAIDCOMISSIONEMPLOYEE_H

#include "CommissionEmployee.h"
#include "FixEmployee.h"



class PaidComissionEmployee:public FixEmployee,public CommissionEmployee
{
    public:
        PaidComissionEmployee(string name,string number,int age,int baseSalary,int comission,int commissionSalary);
        virtual ~PaidComissionEmployee();
        void display();
        void setSalary(int Salary);
        void setBaseSalary(int baseSalary);
        void setCommissionSalary(int salary);
    protected:
    private:
};

#endif // PAIDCOMISSIONEMPLOYEE_H
