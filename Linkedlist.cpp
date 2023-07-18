#include <iostream>
#include "Linkedlist.h"
using namespace std;
int main()
{
    linkedlist x;
    x.pushfront(26);
    x.pushfront(3);
    x.pushfront(4);
    x.pushfront(99);
    x.pushback(68);
    x.print();
}