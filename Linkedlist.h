#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

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
        if (!next)
            cout << data;
        else
            cout << data << "-->";
    }
    node *getnext()
    {
        return next;
    }
    void setnext(node *t)
    {
        next = t;
    }
    // friend class linkedlist;
};
class linkedlist
{
private:
    node *head;
    node *tail;

public:
    node *test;
    int test6;
    linkedlist() : head(nullptr), tail(nullptr) {}
    void pushfront(int x)
    {
        if (!head)
        {
            node *pointer = new node(x);
            head = pointer;
            tail = pointer;
            return;
        }
        if (head)
        {
            node *pointer = new node(x);
            pointer->setnext(head);
            head = tail;
            head = pointer;
            return;
        }
    }
    void pushback(int x)
    {
        node *p = new node(x);
        tail->setnext(p);
        p = tail;
        return;
    }
    void print()
    {
        while (head)
        {
            head->print();
            head = head->getnext();
        }
    }
};
#endif