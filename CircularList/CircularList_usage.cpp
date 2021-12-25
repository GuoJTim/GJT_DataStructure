#include "CircularList.h" // a circular list with last node
//#include "CircularListFull.h" // a circular list with head and tail node and sentinel
#include "../Chain/Chain.h"
#include <iostream>
using namespace std;

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
	
}
