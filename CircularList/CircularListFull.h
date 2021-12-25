#include "../Chain/ChainNode.h" 
#ifndef CircularListFull_H
#define CircularList_H
#define CircularListFull_H //debug 
#define CircularListFullI_H //for iterator

template <class T>
class CircularList{
	private:
		ChainNode<T> *head;
		ChainNode<T> *tail;
		ChainNode<T> *sentinel;
	public:
		static ChainNode<T> *av;//available list
		
		CircularList();
		~CircularList();
		void InsertFront(const T&);
		void InsertTail(const T&);
		void InsertFront(ChainNode<T>*);
		void InsertTail(ChainNode<T>*);
		static ChainNode<T>* GetNode();
		static ChainNode<T>* GetAVlist();
		static void RetNode(ChainNode<T>*&);
		void print();// print all list element
		void Delete(int);
		
		class ChainIterator;
		ChainIterator begin();
		ChainIterator end();
		
		ChainNode<T>* GetSentinel();
		int Length();
};
template <class T>
ChainNode<T> *CircularList<T>::av;

#include "CircularListFull.cpp"
#endif
