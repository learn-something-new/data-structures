// in main.cpp
#include <iostream>
#include "queue.h"

using namespace std;

int main()
{
    Queue a;

    a.add(32);
    a.add(54);
    a.add(47);
    a.add(33);
    a.add(12);
    a.add(99);

    a.display();
    a.del();
    a.del();
    a.del();
    a.del();
    a.display();

    return 0;
};
