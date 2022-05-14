#include <vector>
#include <functional>
#include <algorithm>
#ifndef HeapSort_H
#define HeapSort_H 
#include "../Utils/TreeTextHelper.cpp"
// heap sort is an in-place algorithm
// so that using the ordinary array as inner member array
template <class T,class U = std::less<T> >
class HeapSort{
	private:
		typedef U cmp; 	
		void BuildHeap();
		void HeapIncreaseKey(int i, T key);
		void Heapify(int i,int heapsize);
		int find_target(T &data,int current);
		int PARENT(int i){ 
			return (i-1)/2;
		}
		int LEFT(int i){
			return 2*i+1; // +1 for index = 0
		}
		int RIGHT(int i){
			return 2*i+1+1; // +1 for index = 0
		}
	public:
		
		std::vector<T> arr; // user using vector as input
		HeapSort(std::vector<T> &vecArr);
		void Sort(); // sorting
		void show_tree();
		void show_list(bool asLine = false);
		void HeapDelete(int i); // delete index element
		void HeapDeleteElement(T &obj); // delete object
		void HeapInsert(T key); // insert new element
		T HeapExtract(); // extract the max or min 
		T Top(); // get top
		bool empty(); // to check empty
		
};
#include "HeapSort.cpp"
#endif
