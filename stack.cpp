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
};

int main()
{
    stack a;
    return 0;
};
