#include "LinkedList.h"
#include <iostream>

int main()
{
    linkedList* head;

    // Initialize the list
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

// Initializes the linked list by setting its head to NULL
// Receives: pointer to linkedList** head (reference to the list head)
// Returns: void
void initList(linkedList** head)
{
    *head = NULL;
}

// Adds a new node with a given value at the head of the list
// Receives: pointer to linkedList** head, int value
// Returns: void
void addToHead(linkedList** head, int value)
{
    linkedList* newNode = NULL;

    // Allocate memory for a new node
    newNode = new linkedList;

    // Assign the node's data and set its next pointer
    newNode->data = value;
    newNode->next = *head;

    // Move the head pointer to the new node
    *head = newNode;
}

// Removes the first node from the list (head node)
// Receives: pointer to linkedList** head
// Returns: void
void removeFromHead(linkedList** head)
{
    linkedList* temp = NULL;

    // Guard: do nothing if the list is empty
    if (*head == NULL)
    {
        std::cout << "List is empty, nothing to remove." << std::endl;
        return;
    }

    // Store current head and move to next node
    temp = *head;
    *head = (*head)->next;

    // Free memory of removed node
    delete temp;
}

// Prints all elements of the list from head to tail
// Receives: pointer to linkedList* head
// Returns: void
void printList(linkedList* head)
{
    linkedList* current = NULL;
    current = head;

    // Guard: do nothing if the list is empty
    if (head == NULL)
    {
        std::cout << "List is empty." << std::endl;
        return;
    }

    // Traverse and print each node
    while (current != NULL)
    {
        std::cout << current->data << std::endl;
        current = current->next;
    }
}

// Frees all nodes in the linked list
// Receives: pointer to linkedList** head
// Returns: void
void cleanList(linkedList** head)
{
    linkedList* current = NULL;
    linkedList* temp = NULL;

    // Iterate through the list and free each node
    current = *head;
    while (current != NULL)
    {
        temp = current;
        current = current->next;
        delete temp;
    }

    // Reset the head to NULL
    *head = NULL;
}

// Checks if the linked list is empty
// Receives: pointer to linkedList* head
// Returns: bool (true if empty, false otherwise)
bool isEmpty(linkedList* head)
{
    bool empty = false;

    // Empty if head pointer is NULL
    if (head == NULL)
    {
        empty = true;
    }
    else
    {
        empty = false;
    }

    return empty;
}
