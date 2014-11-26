#include <iostream>
#include "queue.h"

Queue::Queue()
{
    // initalize addition end and deletion end as -1 to signify an empty queue
    front = -1;
    end = -1;
}

void Queue::del()
{
    int tmp;

    if(front == -1)
    {
        std::cout << "QUEUE IS EMPTY!" << std::endl;
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

void Queue::add(int item)
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
            std::cout << "QUEUE IS FULL!" << std::endl;
        }
        else
        {
            t[end] = item;
        }
    }

}

void Queue::display()
{
    if(end != -1)
    {
        for(int x = 0; x <= end; x++)
        {
            std::cout << t[x] << " ";
        }

        std::cout << std::endl;
    }
    else
    {
        std::cout << "QUEUE IS EMPTY!" << std::endl;
    }
}
