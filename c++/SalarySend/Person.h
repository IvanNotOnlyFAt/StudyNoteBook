#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string.h>

using namespace std;


class Person
{
    public:
        Person();
        Person(string,string,int);
        void operator=(const Person &);
        virtual ~Person();
        string getName() const;
        void setName(string);
        string getNumber() const;
        void setNumber(string);
        int getAge() const;
        virtual void display();
        virtual void setSalary(int salary) = 0;
    protected:
    private:
        string m_name;
        string m_employeeNumber;
        int m_age;
};

#endif // PERSON_H
