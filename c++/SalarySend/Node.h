#ifndef NODE_H
#define NODE_H
#include "Person.h"


template <class T>
class Node
{
public:
    Node(T*);
    virtual ~Node();
    T* getItem() const;
    void setItem(T*);
    Node<T> *getNext();
    void setNext(Node*);

protected:
private:
    T* m_item;
    Node<T> *m_next;

};

template <class T>
Node<T>::Node(T* item)
{
    m_item = item;
    m_next = NULL;
}

template <class T>
Node<T>::~Node()
{

}

template <class T>
T *Node<T>::getItem() const
{
    return m_item;
}

template <class T>
void Node<T>::setItem(T *item)
{
    m_item = item;
}

template <class T>
Node<T> *Node<T>::getNext(void)
{
    return m_next;
}


template <class T>
void Node<T>::setNext(Node<T>* next)
{
    m_next = next;
}






#endif // NODE_H
