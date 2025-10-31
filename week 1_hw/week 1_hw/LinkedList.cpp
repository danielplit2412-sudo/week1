#include "LinkedList.h"  
#include <iostream>   
int main()
{
    linkedList* head;
    initList(&head);

    std::cout << "----- Checking if list is empty -----" << std::endl;
    isEmpty(head);

    std::cout << "\n----- Adding elements -----" << std::endl;
    addToHead(&head, 10);
    addToHead(&head, 20);
    addToHead(&head, 30);
    printList(head);

    std::cout << "\n----- Checking if list is empty -----" << std::endl;
    isEmpty(head);

    std::cout << "\n----- Removing elements -----" << std::endl;
    removeFromHead(&head);
    printList(head);
    removeFromHead(&head);
    printList(head);

    std::cout << "\n----- Cleaning list -----" << std::endl;
    cleanList(&head);

    std::cout << "\n----- Final check -----" << std::endl;
    isEmpty(head);

    std::cout << "\nProgram finished successfully." << std::endl;
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
void printList(linkedList* head)
{
   
    if (head == NULL)
    {
        std::cout << "List is empty." << std::endl;
        return;
    }
    std::cout << "list: " << std::endl;

    linkedList* current = head; 

    while (current != NULL)
    {
        std::cout << current->data << std::endl;
        current = current->next;           
    }

    std::cout << std::endl;
}
void cleanList(linkedList** head)
{
    linkedList* current = NULL;
    current = *head;
    while (current != NULL)
    {
        linkedList* temp = current;
        current = current->next;
        delete temp;
    }
    *head = NULL;
    std::cout << "List cleaned successfully." << std::endl;
}
bool isEmpty(linkedList* head)
{
    if (head == NULL)
    {
        std::cout << "List is empty." << std::endl;
        return true;
    }
    else
    {
        std::cout << "List is not empty." << std::endl;
        return false;
    }
}

