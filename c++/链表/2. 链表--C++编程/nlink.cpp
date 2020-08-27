#include <iostream>
#include <stdlib.h>

using namespace std;

class Node
{
public:
    Node(int item);
    ~Node();

    void display() const;

    int m_item;
    Node *m_next;
};

Node::Node(int item)
{
    m_item = item;
    m_next = NULL;
}

Node::~Node()
{
    if(m_next != NULL)
    {
        delete m_next;
    }
}

void Node::display() const
{
    cout << "Item: " << m_item << endl;
}

class Link
{
public:
    Link();
    ~Link();
    void insert_node(Node *p);
    void insert_node_l2b(Node *p);
    void traverse();

    Node *find_node(int m_item);
    Node *remove_node(Node *p);

    Node *m_head;
};

Link::Link()
{
    m_head = NULL;
}

Link::~Link()
{
    Node *p = m_head;
    Node *pre = m_head;
    while (p->m_next != NULL)
    {
        p = pre;
        pre = pre->m_next;
        delete p;
    }
}

void Link::insert_node(Node *p)
{
    if(m_head == NULL)
    {
        m_head = p;
    }else
    {
        p->m_next = m_head->m_next;
        m_head->m_next = p;
    }
}

void Link::insert_node_l2b(Node *p)
{
    Node *pre = m_head;

    while (pre->m_next != NULL)
    {
        if (pre->m_next->m_item > p->m_item)
        {
            break;
        }
        pre = pre->m_next;
    }

    p->m_next = pre->m_next;
    pre->m_next = p;
}

void Link::traverse()
{
    cout << "-----------------------" << endl;
	Node *p = m_head;
	while(p != NULL)
	{
		p->display();
		p = p->m_next;
	}
	cout << "=======================" << endl;
}

Node *Link::find_node(int m_item)
{
	Node *p = m_head->m_next;
	while(p != NULL)
	{
		if ( p->m_item == m_item)
		{
			return p;
		}
		p = p->m_next;
	}

	return NULL;
}

Node *Link::remove_node(Node *p)
{
    Node *pre = m_head;
    while (pre->m_next != NULL)
    {
        if (pre->m_next == p)
        {
            pre->m_next = p->m_next;
            return p;
        }
        pre = pre->m_next;
    }

    return NULL;
}

int main()
{
    Link link;
    Link link1;
	Node *node = new Node(11);
	link.insert_node(node);
	node =  new Node(2);
    link.insert_node(node);
    node =  new Node(31);
    link.insert_node(node);
    node =  new Node(14);
    link.insert_node(node);
    node =  new Node(-5);
    link.insert_node(node);

    node =  new Node(20);
    link1.insert_node(node);
    node =  new Node(10);
    link1.insert_node(node);

    node = link.find_node(-5);
    if (node == NULL)
    {
        cout << "can't find %d\n" << -5;
    }else
    {
        cout << "Remove: " << node->m_item << endl;
       link.remove_node(node);
    }

    link.traverse();
    link1.traverse();
    node = link.find_node(-5);
    if (node == NULL)
    {
        cout << "can't find %d" << -5 << endl;
    }else
    {
        cout << "Remove: " << node->m_item << endl;
       link.remove_node(node);
    }

    link.traverse();
    link1.traverse();
}
