#include <iostream>
#include "Queue.h"
#include "Node.h"
using namespace std;

template <typename T>
Queue<T>::Queue() {
	head = NULL;
	tail = NULL;
}
template <typename T>
void Queue<T>::Enqueue(T val) {
	if (!head) {
		Node<T> *NewNode = new Node<T>(val);
		head = NewNode;
		tail = NewNode;
		return;
	}

	Node<T> *NewNode = new Node<T>(val);
	tail->next = NewNode;
	NewNode->next = NULL;
	tail = NewNode;
	return;
	
}

template <typename T>
void Queue<T>::Dequeue() {
	if (!head) {
		return;
	}
	if (!head->next) {
		delete head;
		head = NULL;
		tail = NULL;
		return;
	}
	Node<T> *temp = head;
	head = head->next;
	delete temp;
	return;

}

template <typename T>
T Queue<T>::peek() {
	if (!head) {
		return -999;
	}

	return head->info;

}

template <typename T>
void Queue<T>::print() {
	if (!head) {
		cout << "Queue is Empty!" << endl;
		return;
	}
	Node<T>* temp = head;
	while (temp)
	{
		cout << temp->info << " ";
		temp = temp->next;
	}

}

template <typename T>
void Queue<T>::emptyQueue() {
	if (!head) {
		return;
	}
	Node<T>* temp = head;
	while (temp)
	{
		Node<T>* del = temp;
		temp = temp->next;
		delete del;
	}
	head = nullptr;

}

template <typename T>
int Queue<T>::sizeOfQueue() {
	if (!head) {
		return 0;
	}
	Node<T>* temp = head;
	int count = 0;
	while (temp)
	{
		count++;
		temp = temp->next;
	}
	return count;
}
template class Queue<int>;