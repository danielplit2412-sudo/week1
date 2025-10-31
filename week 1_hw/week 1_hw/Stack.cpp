#include <iostream>      
#include "Stack.h"       
#include "LinkedList.h"





void push(Stack* s, unsigned int element)
{
    
    if (element == 0)
    {
        std::cout << "Only positive numbers are allowed." << std::endl;
        return;
    }


    addToHead(&(s->top), element);

    std::cout << "Element pushed: " << element << std::endl;
}
