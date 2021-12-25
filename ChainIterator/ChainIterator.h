#include "../Chain/Chain.h"
#ifndef Chain_H
#include "../Chain/Chain.cpp"
#endif



#ifdef Chain_H
#ifndef Chain_Iterator_H
#define Chain_Iterator_H


template <class T>
class Chain<T>::ChainIterator{
	private:
		ChainNode<T> *current;
	public:
		ChainIterator(ChainNode<T> *startNode = 0);
		T& operator*() const;
		T* operator->() const;
		Chain<T>::ChainIterator& operator++();
		Chain<T>::ChainIterator& operator++(int);
		bool operator !=(const ChainIterator right) const;
		bool operator ==(const ChainIterator right) const;
		operator bool();
};
#endif //Chain_Iterator_H
#endif //Chain_H

#ifdef CircularListI_H
#ifndef CircularList_Iterator_H
#define CircularList_Iterator_H
//last node

template <class T>
class CircularList<T>::ChainIterator{
	private:
		ChainNode<T> *current;
		bool circularPoint;
	public:
		ChainIterator(ChainNode<T> *startNode = 0);
		T& operator*() const;
		T* operator->() const;
		CircularList<T>::ChainIterator& operator++();
		CircularList<T>::ChainIterator& operator++(int);
		bool operator !=(const ChainIterator right);
		bool operator ==(const ChainIterator right);
		operator bool();
};
#endif //CircularList_Iterator_H
#endif //CircularList_H
 
#ifdef CircularListFullI_H
#ifndef CircularListFull_Iterator_H
#define CircularListFull_Iterator_H
//head node

template <class T>
class CircularList<T>::ChainIterator{
	private:
		ChainNode<T> *current;
	public:
		ChainIterator(ChainNode<T> *startNode = 0);
		T& operator*() const;
		T* operator->() const;
		CircularList<T>::ChainIterator& operator++();
		CircularList<T>::ChainIterator& operator++(int);
		bool operator !=(const ChainIterator right) const;
		bool operator ==(const ChainIterator right) const;
		operator bool();
};
#endif //CircularList_Iterator_H
#endif //CircularList_H
 
 
#ifndef Iterator_cpp
#define Iterator_cpp
#include "ChainIterator.cpp"
#endif
