#include "LinkedQueue.h"

template<class T>
LinkedQueue<T>::LinkedQueue(){
	head = nullptr;
}

template<class T>
bool LinkedQueue<T>::IsEmpty() const{
	return head == nullptr;
}

template<class T>
T& LinkedQueue<T>::Front() const{
	if(IsEmpty()) throw "error";
	return head->data;
}

template<class T>
T& LinkedQueue<T>::Rear() const{
	if(IsEmpty()) throw "error";
	
	ChainNode<T> *current = head;
	while(current->next != head){
		current = current->next;
	}
	
	return current->data;
}

template <class T>
void LinkedQueue<T>::Push(const T& item){
	if (head == nullptr){
		head = new ChainNode<T>(item);
		head->next = head;
	}else{
		ChainNode<T> *current = head;
		while(current->next != head){
			current = current->next;
		}
		current->next = new ChainNode<T>(item,head);
		//與 stack 不同的地方在於 只有在尾端插入心得值  
	}
}

template <class T>
void LinkedQueue<T>::Pop(){
	if(IsEmpty()) throw "error";
	ChainNode<T> *deleteNode = head;
	if (head->next == head){
		head = nullptr;
	}else{
		ChainNode<T> *current = head;
		while(current->next != head){
			current = current->next;
		}
		head = current->next->next;
		current->next = current->next->next;
	}
	delete deleteNode;
}
