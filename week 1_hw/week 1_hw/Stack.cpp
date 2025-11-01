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
void initStack(Stack* s)
{
    s->top = NULL;
    std::cout << "Stack initialized successfully." << std::endl;
}
void cleanStack(Stack* s)
{
    cleanList(&(s->top));
    std::cout << "Stack cleaned successfully." << std::endl;
}
bool isEmpty(Stack* s)
{
    if (s->top == NULL)
    {
        std::cout << "Stack is empty." << std::endl;
        return true;
    }
    else
    {
        std::cout << "Stack is not empty." << std::endl;
        return false;
    }
}

bool isFull(Stack* s)
{
    return false;
}





