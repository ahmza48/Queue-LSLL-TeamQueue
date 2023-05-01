#ifndef NODE_H
#define NODE_H


template <class T>
class Node
{
public:
	T info;
	Node<T>* next;
	Node(T);
};

#endif // !1