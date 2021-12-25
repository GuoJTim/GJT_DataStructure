#include "../Chain/Chain.h"
#include "../CircularList/CircularListFull.h" //circular list with head and tail
#include "ChainIterator.h"
#include <iostream>
using namespace std;

int main(){
	// build a Chain
	Chain<int> list;
	list.InsertBack(new ChainNode<int>(1));
	list.InsertBack(new ChainNode<int>(2));
	list.InsertBack(new ChainNode<int>(3));
	list.InsertBack(new ChainNode<int>(4));
	// 1 2 3 4
	cout << "list.Print() :" ;list.Print();
	
	Chain<int>::ChainIterator it = list.begin();// iterator
	cout << "iterator :";
	for (;it != list.end();it++){
		cout << *it << " ";
	}
	cout << endl;
	
	
	// build a circular list
	CircularList<int> Clist;
	Clist.InsertTail(1);
	Clist.InsertTail(2);
	Clist.InsertTail(3);
	Clist.InsertTail(4);
	cout << "Clist.print() :" ;Clist.print();
	
	cout << "iterator :" ;
	CircularList<int>::ChainIterator Cit = Clist.begin();
	for(;Cit != Clist.end();Cit++){
		cout << *Cit << " ";
	}cout << endl;
}
