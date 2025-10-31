#include "Queue.h"  
#include <iostream>  
#include <cstdlib>   
#define SIZE 3
int main()
{
	Queue q;

	std::cout << "Initializing queue..." << std::endl;
	initQueue(&q, SIZE);
	std::cout << "Queue initialized successfully!" << std::endl;

	if (isEmpty(&q))
	{
		std::cout << "Queue is empty before adding elements." << std::endl;
	}

	enqueue(&q, 10);
	std::cout << "Element was pushed: 10" << std::endl;

	enqueue(&q, 20);
	std::cout << "Element was pushed: 20" << std::endl;

	enqueue(&q, 30);
	std::cout << "Element was pushed: 30" << std::endl;

	if (isFull(&q))
	{
		std::cout << "Queue is full now." << std::endl;
	}
	else
	{
		std::cout << "Queue is not full yet." << std::endl;
	}

	int value = dequeue(&q);
	std::cout << "Element was poped: " << value << std::endl;

	if (isEmpty(&q))
	{
		std::cout << "Queue is empty." << std::endl;
	}
	else
	{
		std::cout << "Queue is not empty." << std::endl;
	}

	if (isFull(&q))
	{
		std::cout << "Queue is full." << std::endl;
	}
	else
	{
		std::cout << "Queue is not full." << std::endl;
	}

	cleanQueue(&q);
	std::cout << "Queue cleaned successfully." << std::endl;

	return 0;
}
void enqueue(Queue* q, unsigned int newValue)
{
	int newCapacity = 0;
	int i = 0;
	int oldCapacity = 0;
	int divisor = 0;
	if (q->count == q->capacity)
	{
		oldCapacity = q->capacity;
		if (oldCapacity == 0)
		{
			newCapacity = 1;
		}
		else
		{
			newCapacity = q->capacity * 2;
		}
		int* newarr = new int[newCapacity];
		if (oldCapacity == 0)
		{
			divisor = 1;
		}
		else
		{
			divisor = oldCapacity;
		}
			for (i = 0; i < q->count; i++)
			{
				newarr[i] = q->arr[(q->head + i) % divisor];
			}
		delete[] q->arr;
		q->arr = newarr;
		q->capacity = newCapacity;
		q->head = 0;
		q->tail = q->count;
	}
	q->arr[q->tail] = (int)newValue;
	q->tail = (q->tail + 1) % q->capacity;
	q->count++;

}
int dequeue(Queue* q)
{
	int value = 0;
	if (q->count==0)
	{
		return -1;
	}
	value = q->arr[q->head];
	q->head = (q->head + 1) % q->capacity;
	q->count--;
	return value;

}
void initQueue(Queue* q, unsigned int size)
{
	if (size == 0)
	{
		q->arr = NULL;
		q->capacity = 0;
	}
	else
	{
		q->arr = new int[size];
		q->capacity = size;

	}
	q->head = 0;
	q->tail = 0;
	q->count = 0;
}
void cleanQueue(Queue* q)
{
	
	delete[] q->arr;
	q->arr = NULL;
	q->capacity = 0;
	q->head = 0;
	q->tail = 0;
	q->count = 0;
}
bool isEmpty(Queue* s)
{
	if (s->count == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool isFull(Queue* s)
{
	if (s->count == s->capacity)
	{
		return true;
	}
	else
	{
		return false;
	}
}


