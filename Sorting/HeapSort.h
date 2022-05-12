#include <vector>
#include <functional>
#ifndef HeapSort_H
#define HeapSort_H // for iterator

// heap sort is an in-place algorithm
// so that using the ordinary array as inner member array
template <class T,class U = std::less<T> >
class HeapSort{
	private:
		typedef U cmp; 	
		void BuildMaxHeap();
		void HeapIncreaseKey(int i, T key);
		void Heapify(int i,int heapsize);
		int PARENT(int i){ 
			return i/2;
		}
		int LEFT(int i){
			return 2*i;
		}
		int RIGHT(int i){
			return 2*i+1;
		}
		bool compare(int l,int r);
		void swapElement(int l,int r);
		int heapsize; // heapsize
	public:
		
		T *arr; // user using array as input
		std::vector<T> vecArr; // user using vector as input
		int type;// to check if user using arr or vector as the input
		HeapSort(T *arr);
		HeapSort(std::vector<T> &vecArr);
		void Sort(); // sorting
		void show_tree();
		void HeapDelete(int i); // delete index element
		void HeapInsert(T key); // insert new element
		T HeapExtract(); // extract the max or min 
		
};
#include "HeapSort.cpp"
#endif
