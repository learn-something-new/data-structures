#include <iostream>

using namespace std;

// maximum size of the stack
#define MAX 10

class queue
{
    private:
        int t[MAX];
        // the addition end
        int front;
        // the deletion end
        int end;

    public:
        queue()
        {
            // initalize addition end and deletion end as -1 to signify an empty queue
            front = -1;
            end = -1;
        }

        void del()
        {
            int tmp;

            if(front == -1)
            {
                cout << "QUEUE IS EMPTY!" << endl;
            }
            else
            {
                for(int x = 0; x <= end; x++)
                {
                    // if the next item in the queue exists, move it forward
                    if((x+1) <= end)
                    {
                        tmp = t[x+1];
                        t[x] = tmp;
                    }
                    else
                    {
                        end--;

                        // if the beginning of the queue is not empty reset the end of the queue
                        if(end == -1)
                        {
                            front = -1;
                        }
                        else
                        {
                            front = 0;
                        }
                    }
                }
            }
        }

        void add(int item)
        {
            // if this is the first item increment front and end variables
            // else increment end
            if(end == -1 && front == -1)
            {
                front++;
                end++;

                t[end] = item;
            }
            else
            {
                end++;

                // check if we have reached the maximum size, if alert the user
                if(end == MAX)
                {
                    cout << "QUEUE IS FULL!" << endl;
                }
                else
                {
                    t[end] = item;
                }
            }

        }

        void display()
        {
            if(end != -1)
            {
                for(int x = 0; x <= end; x++)
                {
                    cout << t[x] << " ";
                }

                cout << endl;
            }
            else
            {
                cout << "QUEUE IS EMPTY!" << endl;
            }
        }
};

int main()
{
    queue a;

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
