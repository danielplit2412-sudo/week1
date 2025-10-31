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
void removeFromHead(linkedList** head)
{
    linkedList* temp = NULL;
    if (*head == NULL)
    {
        std::cout << "List is empty, nothing to remove." << std::endl;
        return;
    }
    temp=*head;
    *head = (*head)->next;
    std::cout << "Removed element: " << temp->data << std::endl;
    delete temp;

}
