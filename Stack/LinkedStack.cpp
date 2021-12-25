#include "LinkedStack.h"

template<class T>
LinkedStack<T>::LinkedStack(){
	top = nullptr;
}


template<class T>
void LinkedStack<T>::Push(const T& e){
	top = new ChainNode<T>(e,top);
}

template<class T>
void LinkedStack<T>::Pop(){
	if(IsEmpty()) throw "Stack is Emtpy. Cannot Delete";
	ChainNode<T> *delNode = top;
	top = top->next;
	delete delNode;
}

template<class T>
T& LinkedStack<T>::Top(){
	return top->data;
}

template<class T>
bool LinkedStack<T>::IsEmpty(){
	return top == nullptr;
}
