// in main.cpp
#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
    Stack a;

    // push the numbers 3, 5, and 2
    a.push(3);
    a.push(5);
    a.push(2);

    // pop all 3 values and cout to the user
    cout << a.pop() << " was popped" << endl;
    cout << a.pop() << " was popped" << endl;
    cout << a.pop() << " was popped" << endl;

    return 0;
};
