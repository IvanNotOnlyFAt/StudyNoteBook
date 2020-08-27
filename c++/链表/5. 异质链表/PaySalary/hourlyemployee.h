#ifndef __HOURLY_EMPLOYEE_H
#define __HOURLY_EMPLOYEE_H

#include <iostream>
#include "employee.h"

using namespace std;
class HourlyEmployee:public Employee
{
public:
    HourlyEmployee(const MyString &name = "xiaoming",
             const MyString &phone = "13356564545",
             double wageForHour = 30,
             double wageForOverTime = 35,
             int hours = 48);

    void setWageForHour(double wageForHour);
    double getWageForHour() const;
    void setWageForOverTime(double wageForOverTime);
    double setWageForOverTime() const;
    void setHours(int hours);
    int getHours() const;

    double earnings()const;
    void display()const;
private:
    double m_wageForHour;
    double m_wageForOverTime;
    int m_hours;
};

#endif // __HOURLY_EMPLOYEE_H


