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
int pop(Stack* s)
{
    if (s->top == NULL)
    {
        std::cout << "Stack is empty, nothing to pop." << std::endl;
        return -1;
    }

    int value = s->top->data;
    removeFromHead(&(s->top));
    std::cout << "Element popped: " << value << std::endl;
    return value;

}




