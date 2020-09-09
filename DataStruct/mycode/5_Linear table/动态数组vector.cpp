#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <list>
using namespace std;

class Person
{
public:
    Person();
    Person(const char *name, int age);
    ~Person();
    void setName(const char* name);
    void setAge(int age);
    const char *getName(void) const;
    int getAge(void) const;
    virtual void display(void) const;
private:
	char *m_name;
	int m_age;
};

Person::Person()
{
    m_name = NULL;
    m_age = 0;
}

Person::Person(const char *name, int age)
{
    m_name = new char[strlen(name)+1];	//动态数组，随输入确定大小
	strcpy(m_name, name);
	m_age = age;
}

Person::~Person()
{
    if(m_name != NULL)
    {
        delete []m_name;
    }
}

void Person::setName(const char* name)
{
	if(m_name != NULL)
    {
        delete []m_name;
    }
	m_name = new char[strlen(name)+1];	//动态数组，随输入确定大小
	strcpy(m_name, name);
}

void Person::setAge(int age)
{
	m_age = age;
}

const char *Person::getName(void) const
{
    return m_name;
}
int Person::getAge(void) const
{
    return m_age;
}

void Person::display() const
{
	cout << m_name << ", " << m_age << endl;
}

int main(void)
{
	//person类型的容器vec
    vector<Person> vec;
	
    vec.push_back(Person("小绿", 20));
    vec.push_back(Person("小明", 15));
    vec.push_back(Person("小红", 15));
    vec.push_back(Person("小黑", 15));
    vec.push_back(Person("小白", 15));

    vector<Person>::iterator it;
	
    for(it = vec.begin(); it != vec.end(); it++)
    {
        it->display();
    }

    return 0;
}

