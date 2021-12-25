#include "CircularList.h"

#include <iostream>
template<class T>
CircularList<T>::CircularList(){
	av = nullptr;
	last = nullptr;
}


template<class T>
void CircularList<T>::InsertFront(const T& e){
	ChainNode<T> *newNode = new ChainNode<T>(e);
	if (last != nullptr){
		newNode->next = last->next;
		last->next = newNode;
	}else{
		last = newNode;
		newNode->next = newNode; // 指向自己 因為是 Circular List 
	}
} 


template<class T>
void CircularList<T>::InsertTail(const T& e){ // insert last
	ChainNode<T> *newNode = new ChainNode<T>(e);
	if (last != nullptr){
		newNode->next = last->next;
		last->next = newNode;
		last = newNode;
	}else{
		last = newNode;
		newNode->next = newNode; // 指向自己 因為是 Circular List 
	}
} 

template<class T>
void CircularList<T>::print(){
	ChainNode<T> *first = last->next;
	if (first == nullptr) return;
	if (last == last->next){
		std::cout << last->data << std::endl;
		return;
	}
	
	do{
		std::cout << first->data << " ";
		first = first->next;
	}while(first != last);
	std::cout << first->data;
	std::cout << std::endl;
}


template <class T>
void CircularList<T>::Delete(int index){
	ChainNode<T> *current = last;
	if (last == last->next && index == 0){
		delete last;
		last = NULL;
	}
	for (int i = 0 ; i < index ; i++){
		if (current->next == last){
			throw "out of range";
		}
		current = current->next;
	}
	ChainNode<T> *deleteNode = current->next;
	if (current->next == last){ // remove last node
		last = current;
	}
	current->next = current->next->next;
	delete deleteNode;
}



template<class T>
typename CircularList<T>::ChainIterator CircularList<T>::begin(){
	return CircularList<T>::ChainIterator(last->next);
} 


template<class T>
typename CircularList<T>::ChainIterator CircularList<T>::end(){
	return CircularList<T>::ChainIterator(last->next);
} 



template<class T>
ChainNode<T>* CircularList<T>::GetNode(){
	ChainNode<T> *x;
	if(av){
		x = av;
		av = av->next;
		x->next = nullptr;// remove next link
	} else x = nullptr ;// return empty 
	return x;
}


template<class T>
void CircularList<T>::RetNode(ChainNode<T>*& x){
	x->next = av;
	av = x;
	x = 0;
}



template<class T>
ChainNode<T>* CircularList<T>::GetAVlist(){
	ChainNode<T> *x;
	if(av){
		x = av;
		av = nullptr;
	} else x = nullptr ;// return empty 
	return x;
}



/*
當 LL 是以 CircularList 方式建構時 ， 解構 可以將 整串鏈結串列 鏈結到 av 之前  
*/
template <class T>
CircularList<T>::~CircularList(){
	if (last){
		ChainNode<T> *first = last->next;
		last->next = av;
		av = first;
		last = 0;
	}
}
