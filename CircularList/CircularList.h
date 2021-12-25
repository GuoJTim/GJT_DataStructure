#include "../Chain/ChainNode.h"
#ifndef CircularList_H
#define CircularList_H
#define CircularListFull_H // debug
#define CircularListI_H // for iterator

template <class T>
class CircularList{
	private:
		ChainNode<T> *last;
	public:
		static ChainNode<T> *av;//available list
		
		CircularList();
		~CircularList();
		void InsertFront(const T&);
		void InsertTail(const T&);
		static ChainNode<T>* GetNode();
		static ChainNode<T>* GetAVlist();;
		void RetNode(ChainNode<T>*&);
		void print();// print all list element
		void Delete(int);
		
		class ChainIterator;
		ChainIterator begin();
		ChainIterator end();
};
template <class T>
ChainNode<T> *CircularList<T>::av;
#include "CircularList.cpp"
#endif
