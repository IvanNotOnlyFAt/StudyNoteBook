#include <iostream>
using namespace std;

#include "employee.h"
#include "salariedemployee.h"
#include "commissionemployee.h"
#include "basepluscommissionemployee.h"
#include "hourlyemployee.h"

int main()
{
    Employee e;
    cout << "Employee Salary: " <<  e.earnings() << endl;
    e.display();

    SalariedEmployee se;
    cout << "\nSalariedEmployee Salary: " <<  se.earnings() << endl;
    se.display();

    CommissionEmployee ce;
    cout << "\nCommissionEmployee Salary: " <<  ce.earnings() << endl;
    ce.display();

    BasePlusCommissionEmployee be;
    cout << "\nBasePlusCommissionEmployee Salary: " <<  be.earnings() << endl;
    be.display();

    HourlyEmployee he;
    cout << "\nHourlyEmployee Salary: " <<  he.earnings() << endl;
    he.display();

    return 0;
}
