#include "../Chain/ChainNode.h"
#ifndef LinkedQueue_H
#define LinkedQueue_H

template <class T>
class LinkedQueue{
	friend class ChainNode<T>;
	private:
		ChainNode<T> *head;
	public:
		LinkedQueue();
		bool IsEmpty() const;
		T& Front() const;
		T& Rear() const;
		void Push(const T& item);
		void Pop();
};
#include "LinkedQueue.cpp"
#endif
