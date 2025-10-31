#pragma once
#include <iostream>

typedef struct linkedList
{
    int data;
    linkedList* next;
} linkedList;

// Initializes an empty list
void initList(linkedList** head);

// Adds an element to the top of the list
void addToHead(linkedList** head, int value);

// Removes an element from the top of the list
void removeFromHead(linkedList** head);

// Prints the entire list
void printList(linkedList* head);

// Clears the entire list from memory
void cleanList(linkedList** head);

// Checks if the list is empty
bool isEmpty(linkedList* head);
