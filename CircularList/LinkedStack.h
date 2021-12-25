#include "../Chain/ChainNode.h"
#ifndef LinkedStack_H
#define LinkedStack_H

template <class T>
class LinkedStack{
	friend class ChainNode<T>;
	private:
		ChainNode<T> *top;
	public:
		LinkedStack();
		bool IsEmpty() const;
		T& Top() const;
		void Push(const T& item);
		void Pop();
};
#include "LinkedStack.cpp"
#endif
