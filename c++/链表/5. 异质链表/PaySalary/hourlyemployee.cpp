#include "hourlyemployee.h"

HourlyEmployee::HourlyEmployee(const MyString &name,
             const MyString &phone,
             double wageForHour,
             double wageForOverTime,
             int hours):Employee(name, phone)
{
    m_wageForHour = wageForHour;
    m_wageForOverTime = wageForOverTime;
    m_hours = hours;
}

void HourlyEmployee::setWageForHour(double wageForHour)
{
    m_wageForHour = wageForHour;
}
double HourlyEmployee::getWageForHour() const
{
    return m_wageForHour;
}
void HourlyEmployee::setWageForOverTime(double wageForOverTime)
{
    m_wageForOverTime = wageForOverTime;
}
double HourlyEmployee::setWageForOverTime() const
{
    return m_wageForOverTime;
}
void HourlyEmployee::setHours(int hours)
{
    m_hours = hours;
}
int HourlyEmployee::getHours() const
{
    return m_hours;
}

double HourlyEmployee::earnings()const
{
    double salary = 0;
    if(m_hours > 40)
    {
        salary = 40 * m_wageForHour
                + (m_hours - 40) * m_wageForOverTime;
    }else
    {
        salary = m_hours * m_wageForHour;
    }

    return salary;
}
void HourlyEmployee::display()const
{
    cout << "HourlyEmployee::Name: " << getName() << endl;
    cout << "HourlyEmployee::Phone: " << getPhone() <<endl;
    cout << "HourlyEmployee::WageForHour: " << m_wageForHour << endl;
    cout << "HourlyEmployee::WageForOverTime: " << m_wageForOverTime << endl;
    cout << "HourlyEmployee::Hours: " << m_hours <<endl;
}
