#include <iostream>

using namespace std;

// maximum size of the stack
#define MAX 10

class stack
{
    private:
        int arr[MAX];
        int top;

    public:
        // constructor
        stack()
        {
            // set top location to -1 indicating a empty stack
            top = -1;
        }

        // add to the stack
        void push(int a)
        {
            // increment top
            top++;

            // if top is below limit go ahead and add
            // else cout an error and de-increment top
            if(top<MAX)
            {
                arr[top] = a;
            }
            else
            {
                cout << "STACK FULL!" << endl;
                top--;
            }
        }

        // delete from top of stack and return item
        int pop()
        {
            // if top is -1 the stack is empty so cout an error
            // else remove the top item from the stack
            if(top == -1)
            {
                cout << "STACK IS EMPTY!" << endl;

                return 0;
            }
            else
            {
                int data = arr[top];
                arr[top] = 0;
                top--;

                return data;
            }
        }
};

int main()
{
    stack a;

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
