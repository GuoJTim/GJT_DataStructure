#include "LinkedStack.h"

template<class T>
LinkedStack<T>::LinkedStack(){
	top = nullptr;
}

template<class T>
bool LinkedStack<T>::IsEmpty() const{
	return top == nullptr;
}

template<class T>
T& LinkedStack<T>::Top() const{
	if (IsEmpty()) throw "error";
	return top->data;
}

template<class T>
void LinkedStack<T>::Push(const T& item){
	if (top == nullptr){
		top = new ChainNode<T>(item);
		top->next = top;// to know
	}else{
		ChainNode<T> *current = top;
		while(current->next != top){ // to the last
			current = current->next;
		}
		current->next = new ChainNode<T>(item,top);
		top = current->next;
	}
}

template <class T>
void LinkedStack<T>::Pop(){
	if (IsEmpty()) throw "error";
	ChainNode<T> *deleteNode = top;
	if (top->next == top){
		top = nullptr;
	}else{
		ChainNode<T> *current = top;
		while(current->next != top){ // to the last
			current = current->next;
		}
		top = current->next->next;
		current->next = current->next->next;
	}
	delete deleteNode;
}
