#include <iostream>
using namespace std;
class node
{
private:
    int data;
    node *next;

public:
    node(int x)
    {
        data = x;
        next = nullptr;
    }
    void print()
    {
        cout << data << "-->";
    }

    friend class linkedlist;
};
class linkedlist
{
private:
    node *head = nullptr;
    node *tail = nullptr;

public:
    node *test;
    int test6;
    void pushfront(int x)
    {
        if (!head)
        {
            node *pointer = new node(x);
            head = pointer;
            tail = pointer;
        }
    }
    void print()
    {
        while (head)
        {
            head->print();
            head = head->next;
        }
    }
};
int main()
{
    linkedlist x;
    x.pushfront(3);
    x.print();
}