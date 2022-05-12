#include "HeapSort.h"

template <class T,class U>
HeapSort<T,U>::HeapSort(T *arr){
	type = 1;// the array type
	this->arr = arr;//point to the arr
}

template <class T,class U>
HeapSort<T,U>::HeapSort(std::vector<T> &vecArr){
	type = 2;// the vector type
	this->vecArr = vecArr;
}

template <class T,class U>
void HeapSort<T,U>::Sort(){
	
}

template <class T,class U>
void HeapSort<T,U>::BuildMaxHeap(){
	
}

template <class T,class U>
void HeapSort<T,U>::HeapIncreaseKey(int i, T key){
	
}

template <class T,class U>
bool HeapSort<T,U>::compare(int l,int r){
	if (type == 1){
		return cmp()(arr[l],arr[r]);
	}else if (type == 2){
		return cmp()(vecArr[l],vecArr[r]);
	}
	return false;
}

template <class T,class U>
void HeapSort<T,U>::swapElement(int l,int r){
	if (type == 1){
		return swap(arr[l],arr[r]);
	}else if (type == 2){
		return swap(vecArr[l],vecArr[r]);
	}
	return false;
}


template <class T,class U>
void HeapSort<T,U>::Heapify(int i,int heapsize){
	int l = LEFT(i);
	int r = RIGHT(i);
	int v;
	if (l <= heapsize && compare(l,i)){
		v = l;
	}else v = i;
	if (r <= heapsize && compare(r,v)){
		v = r;
	}
	if (v != i){
		swapElement(i,v);
		Heapify(v,heapsize); 
	}
}

template <class T,class U>
void HeapSort<T,U>::show_tree(){
	
}

template <class T,class U>
void HeapSort<T,U>::HeapDelete(int i){
	
}


template <class T,class U>
void HeapSort<T,U>::HeapInsert(T key){
	
}

template <class T,class U>
T HeapSort<T,U>::HeapExtract(){
	
}




