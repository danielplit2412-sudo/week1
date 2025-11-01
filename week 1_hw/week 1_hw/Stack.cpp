#include <iostream>
#include "Stack.h"
#include "LinkedList.h"

int main()
{
    // יצירת מחסנית חדשה
    Stack s;

    // אתחול המחסנית
    initStack(&s);

    std::cout << "----- Checking if stack is empty -----" << std::endl;
    isEmpty(&s);

    std::cout << "\n----- Adding elements (push) -----" << std::endl;
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    std::cout << "\n----- Removing elements (pop) -----" << std::endl;
    pop(&s);
    pop(&s);

    std::cout << "\n----- Checking if stack is empty again -----" << std::endl;
    isEmpty(&s);

    std::cout << "\n----- Cleaning stack -----" << std::endl;
    cleanStack(&s);

    std::cout << "\n----- Final check -----" << std::endl;
    isEmpty(&s);

    std::cout << "\nProgram finished successfully :)" << std::endl;

    return 0;
}

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





