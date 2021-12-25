//#include "CircularList.h" // a circular list with last node
#include "CircularListFull.h" // a circular list with head and tail node and sentinel
#include "../Chain/Chain.h"
#include <iostream>
using namespace std;

bool comp(int a , int b){
	return a < b;
}

int main(){
	
	CircularList<int> list;
	list.InsertFront(5);//insert front
	list.print();
	
	list.InsertTail(4);//insert tail
	list.print();
	
	list.Delete(0); // remove first node
	list.print();
	
	list.InsertFront(5);
	list.Delete(1); // remove last node
	list.print();
	
	
	
	{
		CircularList<int> testAVlist;// when destructor list will replace to av list
		testAVlist.InsertFront(5);
		testAVlist.InsertFront(4);
		testAVlist.InsertFront(3);
		cout<<"test AV list:"; testAVlist.print();
	}
	Chain<int> chain(CircularList<int>::GetAVlist());
	cout << "get AV list:"; chain.Print();
	
	list.InsertFront(5);
	list.InsertFront(4);
	list.InsertFront(3);
	cout << "org list:";list.print();
	CircularList<int> copyClass(list);
	cout << "copy list:";copyClass.print();
	copyClass.Delete(0);
	cout << "copy list (delete 0):";copyClass.print();
	cout << "org list:";list.print();
	
	CircularList<int> empty;
	CircularList<int> copyEmpty(empty);
	copyEmpty.InsertFront(0);
	copyEmpty.print();
	
	
#ifdef CircularListFull_H
	// test for custom compare function usage
	CircularList<int> org_insert_sort;
	org_insert_sort.InsertSort(new ChainNode<int>(1));
	org_insert_sort.InsertSort(new ChainNode<int>(4));
	org_insert_sort.InsertSort(new ChainNode<int>(2));
	org_insert_sort.print();
	
	CircularList<int> custom_insert_sort;
	custom_insert_sort.InsertSort(new ChainNode<int>(1),&comp);
	custom_insert_sort.InsertSort(new ChainNode<int>(4),&comp);
	custom_insert_sort.InsertSort(new ChainNode<int>(2),&comp);
	custom_insert_sort.print();
#endif 
}
