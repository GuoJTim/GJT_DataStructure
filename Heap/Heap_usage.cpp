#include "Heap.h"
#include <functional>
#include <iostream>
using namespace std;

int main(){
	//Build a heap
	Heap<int,greater<int>> myHeap;
	myHeap.Insert(5);
	myHeap.show_list();
	myHeap.Insert(4);
	myHeap.show_list();
	myHeap.Insert(7);
	myHeap.show_list();
	// a max heap
	
	Heap<int> myHeap2;
	myHeap2.Insert(5);
	myHeap2.show_list();
	myHeap2.Insert(4);
	myHeap2.show_list();
	myHeap2.Insert(7);
	myHeap2.show_list();
	// a min heap
	
	
	Heap<int,greater<int>> myHeap3({2,4,3,6,7,9,3,8,6});
	cout << "show sequence list:";myHeap3.show_list(); //with an array
	cout << "show the heap tree:\n";myHeap3.show_tree(); // show with heap tree
	myHeap3.Delete(3);
	cout << "delete element 3\n";myHeap3.show_tree();
	myHeap3.Sort();
	cout << "heapsort:"; myHeap3.show_list();
	myHeap3.Delete(3);
	cout << "after delete the heap will not be ordered:";myHeap3.show_list();
	cout << "and delete an element after the sort the heap will not be satisfy max/min heapify:\n"; myHeap3.show_tree();
	
	
	
	Heap<int,greater<int>> myHeap4( {9, 4, 1, 6, 7, 3, 8, 2, 5});
	myHeap4.Sort();
	cout << "sorted arr:";myHeap4.show_list(); //with an array
	cout << "sorted heap tree (first element and last element swap):\n";myHeap4.show_tree(); // show with heap tree
	
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	Heap<int,greater<int>> hh({21,10,20,4,9,13,18,1,2,8,9,10,12,14,16});
	hh.show_tree();
	hh.Delete(4);
	hh.show_tree();
	while(hh.size()){
		int n = hh.extract();
		cout << n << endl;
	}
	
	
}
