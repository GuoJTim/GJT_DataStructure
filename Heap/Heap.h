#ifndef Heap_H
#define Heap_H // for iterator
#include <vector>
#include <functional>
// remove type instead of using compare function



template <class T,class U = std::less<T> >
class Heap{
	private:
		typedef U cmp; 							// compare 
		std::vector<T> arr;						// 1 is used for the 0 index
		void heapify(int i,int heapsize);		// heapify
		void build_heap();						// build a max/min heap
		int find_target(T &data,int current);	// on delete element
		
	public:
		
		Heap();
		Heap(std::vector<T> arr);
		void Insert(T data);
		T top();
		T extract();
		int size();
		void Sort();
		void show_list();
		void show_tree();
		void sequence_order();
		void Delete(T data);
};

#include "Heap.cpp"
#endif
