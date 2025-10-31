#include "LinkedList.h"  
#include <iostream>   
int main()
{

	return 0;
}
void initList(linkedList** head)
{
	*head = NULL;  
}
void addToHead(linkedList** head, int value)
{
    linkedList* newNode = new linkedList;
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}
