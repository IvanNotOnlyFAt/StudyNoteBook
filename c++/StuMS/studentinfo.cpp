
#include "studentinfo.h"

StudentInfo::StudentInfo()
{
    m_id.clear();
    m_name.clear();
    m_degree.clear();
    m_major.clear();
}

StudentInfo::StudentInfo(const string &id, const string &name,
                         const string &degree, const string &major)
{
    m_id = id;
    m_name = name;
    m_degree = degree;
    m_major = major;
}

void StudentInfo::display(void)const
{
    cout << "ID: " << m_id << endl;
    cout << "Name: " << m_name << endl;
    cout << "Degree: " << m_degree << endl;
    cout << "Major: " << m_major << endl;
}

void StudentInfo::setID(const string &id)
{
    m_id = id;
}

void StudentInfo::setName(const string &name)
{
    m_name = name;
}

void StudentInfo::setDegree(const string &degree)
{
    m_degree = degree;
}

void StudentInfo::setMajor(const string &major)
{
    m_major = major;
}

const string &StudentInfo::getID() const
{
    return m_id;
}
const string &StudentInfo::getName() const
{
    return m_name;
}
const string &StudentInfo::getDegree() const
{
    return m_degree;
}
const string &StudentInfo::getMajor() const
{
    return m_major;
}
