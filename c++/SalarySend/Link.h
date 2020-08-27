#ifndef LINK_H
#define LINK_H
#include "Person.h"
#include "node.h"

class Link
{
    public:
        Link();
        virtual ~Link();
        void insertNode(Person*);
        void removeNode(Person*);
        void findNode(string number);
        void traverse(void);
        void findNode(Person*);
        void destory(void);
    protected:
    private:
        Node<Person> *m_head;
};

#endif // LINK_H
