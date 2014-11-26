// stack.h

// maximum size of the stack
#define MAX 10

class Stack 
{
    private:
        int arr[MAX];
        int top;

    public:
        Stack();
        void push(int a);
        int pop();
};
