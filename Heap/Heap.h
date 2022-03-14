#ifndef Heap_H
#define Heap_H // for iterator
#include <vector>


typedef enum HeapType{
	MAX_HEAP,
	MIN_HEAP
}HeapType;



template <class T>
class Heap{
	public:
		std::vector<T> arr;// 1 is used for the 0 index
		HeapType type;
		Heap();
		Heap(HeapType type);
		Heap(HeapType type,std::vector<T> arr);
		void Insert(T data);
		T top();
		T extract();
		void heapify(int i,int heapsize);
		void build_heap();
		int size();
		void Sort();
		void show_list();
		void show_tree();
		void sequence_order();
		void Delete(T data);
		int find_target(T &data,int current);
};

#include "Heap.cpp"
#endif
