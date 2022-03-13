#include "Heap.h"
#include <iostream>
using namespace std;

int main(){
	//Build a heap
	Heap<int> myHeap(MAX_HEAP);
	myHeap.Insert(5);
	myHeap.show_list();
	myHeap.Insert(4);
	myHeap.show_list();
	myHeap.Insert(7);
	myHeap.show_list();
	// a max heap
	
	Heap<int> myHeap2(MIN_HEAP);
	myHeap2.Insert(5);
	myHeap2.show_list();
	myHeap2.Insert(4);
	myHeap2.show_list();
	myHeap2.Insert(7);
	myHeap2.show_list();
	// a min heap
	
	
	Heap<int> myHeap3(MAX_HEAP,{2,4,3,6,7,9,3,8,6});
	myHeap3.show_list(); //with an array
	myHeap3.show_tree(); // show with heap tree
	myHeap3.Delete(3);
	myHeap3.show_tree();
//	myHeap3.show_tree(); 
//	
//	
//	Heap<int> myHeap4(MAX_HEAP, {9, 4, 1, 6, 7, 3, 8, 2, 5});
//	myHeap4.Sort();
//	myHeap4.show_list(); //with an array
//	myHeap4.show_tree(); // show with heap tree
}
