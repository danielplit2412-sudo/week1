

#include "Utils.h"
#include "Stack.h"
#include "LinkedList.h"
#include <iostream>

void reverse(int* nums, unsigned int size)
{
    if (nums == nullptr || size == 0)
        return;

    Stack s;
    initStack(&s);

    for (unsigned int i = 0; i < size; i++)
    {
        push(&s, nums[i]);
    }

 
    for (unsigned int i = 0; i < size; i++)
    {
        nums[i] = pop(&s);
    }

    cleanStack(&s);
}
