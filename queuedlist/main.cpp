// in main.cpp
#include <iostream>
#include "queue.h"

using namespace std;

int main()
{
    Queue list;

    list.add(10);
    list.add(4);
    list.add(17);
    list.add(71);

    cout << list.del() << endl;

    return 0;
}
