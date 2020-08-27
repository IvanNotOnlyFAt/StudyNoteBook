#ifndef FIXEMPLOYEE_H
#define FIXEMPLOYEE_H

#include "Person.h"

class FixEmployee:virtual public Person
{
    public:
        FixEmployee(string name,string number,int age,int fixSalary);
        virtual ~FixEmployee();
        void setSalary(int salary);
        void display(void);
        int getFixSalary(void);
        void setFixSalary(int salary);
    protected:
    private:
        int m_fixSalary;
};

#endif // FIXEMPLOYEE_H
