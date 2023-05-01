#include <iostream>
#include "Node.h"
using namespace std;

template <typename T>
Node<T>::Node(T val) {
	info = val;
	next = NULL;
}

template class Node<int>;
