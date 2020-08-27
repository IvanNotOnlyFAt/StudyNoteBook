#ifndef HOUREMPLOYEE_H
#define HOUREMPLOYEE_H
#include "Person.h"

class HourEmployee:virtual public Person
{
    public:
        HourEmployee(string,string,int,int,int);
        virtual ~HourEmployee();

        void display();
        int getHour(void);
        int getHourSalary(void);
        void setSalary(int salary);
    protected:
    private:
        int m_hour;
        int m_hourSalary;
};

#endif // HOUREMPLOYEE_H
