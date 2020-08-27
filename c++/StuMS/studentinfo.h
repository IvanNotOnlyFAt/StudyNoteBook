#ifndef __STUDENT_INFO_H
#define __STUDENT_INFO_H

#include <iostream>
#include <list>
using namespace std;

class StudentInfo
{
public:
    StudentInfo();
    StudentInfo(const string &id, const string &name,
                const string &degree, const string &major);

    void display(void) const;

    void setID(const string &id);
    void setName(const string &name);
    void setDegree(const string &degree);
    void setMajor(const string &major);

    const string &getID() const;
    const string &getName() const;
    const string &getDegree() const;
    const string &getMajor() const;

private:
    string m_id;
    string m_name;
    string m_degree;
    string m_major;
};

typedef list<StudentInfo> StudentInfoList;

#endif // __STUDENT_INFO_H
