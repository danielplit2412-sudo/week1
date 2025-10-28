#include "Queue.h"  
#include <iostream>  
#include <cstdlib>   
int main()
{

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
