// stack.h

// maximum size of the stack
#define MAX 10

struct node
{
    int data;
    node *link;
};

class Stack
{
    private:
        node* top;

    public:
        Stack();
        ~Stack();
        void push(int a);
        int pop();
};
