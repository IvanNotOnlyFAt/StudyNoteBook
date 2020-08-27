#include "Link.h"
#include <iostream>
using namespace std;


Link::Link()
{
    m_head = NULL;
}


Link::~Link()
{
    if(m_head != NULL)
    {
        m_head = NULL;
    }
}


void Link::insertNode(Person *Pe)
{
    Node<Person> *p = new Node<Person>(Pe);
    if(m_head == NULL)
    {
        m_head = p;
    }else
    {
        p->setNext(m_head);
        m_head = p;
    }
}


void Link::traverse(void)
{
    Node<Person> *p = m_head;
    while(p != NULL)
    {
        p->getItem()->display();
        p = p->getNext();
    }
}

 void Link::removeNode(Person* pe)
 {
     Node<Person> *pre = m_head;
     if(m_head->getItem() == pe)
     {
         m_head = m_head->getNext();
     }
     while(pre->getNext() != NULL)
     {
         if(pre->getNext()->getItem() == pe)
         {
             pre->setNext(pre->getNext()->getNext());
             delete pre->getNext();
         }
         pre = pre->getNext();
     }

 }


 void Link::findNode(string number)
 {
    Node<Person> *p = m_head;
    while(p->getNext() != NULL)
    {
        if(p->getItem()->getNumber() == number)
        {
            cout << "找到员工的信息如下" << endl;
            p->getItem()->display();
            return;
        }
        p = p->getNext();
    }
    cout << "没有员工号为" << number << "的员工" << endl;
 }


void Link::destory(void)
{
    Node<Person> *p = m_head;
    while(m_head != NULL)
    {
        p = m_head;
        m_head = m_head->getNext();
        delete p;
    }
}
