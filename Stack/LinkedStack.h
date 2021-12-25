#include "../Chain/ChainNode.h"
#ifndef LinkedStack_H
#define LinkedStack_H

// note that LIFO 
// so here is the sequence: +player4 +player3 + player2 + top
//
//  top
//  layer2
//  layer3
//  layer4
//
//

template<class T>
class LinkedStack{
	private:
		ChainNode<T> *top;
	public:
		LinkedStack();
		void Push(const T& e);
		void Pop();
		T& Top();
		bool IsEmpty();
};


#endif
