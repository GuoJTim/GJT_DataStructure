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
		void BuildHeap(std::vector<T> &arr,int begin,int end);
		void HeapIncreaseKey(std::vector<T> &arr,int i, T& key);
		void Heapify(std::vector<T> &arr,int i,int heapsize,int begin=0);
		int find_target(std::vector<T> &arr,T &data,int current);
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
		HeapSort(std::vector<T> &arr);
		HeapSort();
		void Sort(); // inner vector sorting
		void Sort(std::vector<T> &arr); // sorting
		void Sort(std::vector<T> &arr,int begin,int end); // sorting
		void show_tree();
		void show_list(bool asLine = false);
		void HeapDelete(std::vector<T> &arr,int i); // delete index element
		void HeapDelete(int i); // delete index element
		void HeapDeleteElement(std::vector<T> &arr,T &obj); // delete object
		void HeapDeleteElement(T &obj); // delete object
		void HeapInsert(std::vector<T> &arr,T &key); // insert new element
		void HeapInsert(T &key); // insert new element
		T HeapExtract(std::vector<T> &arr); // extract the max or min 
		T HeapExtract(); // extract the max or min 
		T Top(std::vector<T> &arr); // get top
		T Top(); // get top
		bool empty(std::vector<T> &arr); // to check empty
		bool empty(); // to check empty
		
};
#include "HeapSort.cpp"
#endif
