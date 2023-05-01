#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"

template <class T>
class Queue
{
private:
	Node<T>* head;
	Node<T>* tail;
public:
	Queue();
	void Enqueue(T val);
	void Dequeue();
	T peek();
	void print();
	void emptyQueue();
	int sizeOfQueue();
};

#endif