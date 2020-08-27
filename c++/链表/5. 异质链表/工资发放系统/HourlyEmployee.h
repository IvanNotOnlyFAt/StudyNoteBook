
#ifndef HOURLY_H
#define HOURLY_H

#include "Employee.h" // Employee class definition

class HourlyEmployee : public Employee
{
public:
   HourlyEmployee( const string &, const string &,
      const string &, double = 0.0, double = 0.0 );

   void setWage( double ); // set hourly wage
   double getWage() const; // return hourly wage

   void setHours( double ); // set hours worked
   double getHours() const; // return hours worked

   // keyword virtual signals intent to override
   virtual double earnings() const; // calculate earnings
   virtual void print() const; // print HourlyEmployee object
private:
   double wage; // wage per hour
   double hours; // hours worked for week
}; // end class HourlyEmployee

#endif // HOURLY_H

