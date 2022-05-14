#include "HeapSort.h"
#include <iostream>
template <class T,class U>
HeapSort<T,U>::HeapSort(std::vector<T> &arr){
	for (T obj:arr){
		HeapInsert(obj);	
	}
}

template <class T,class U>
void HeapSort<T,U>::Sort(){
	int size = arr.size();//get size
	BuildHeap();
	for (int i = size - 1 ; i>= 0 ; i--){
		std::swap(arr[0],arr[size-1]);
		Heapify(0,size-1);
		size--;
	}
}

template <class T,class U>
void HeapSort<T,U>::BuildHeap(){
	int size = arr.size();//get size
	for (int i = (size / 2 - 1) ; i >= 0 ; i--){
		Heapify(i,size);
	}
}

template <class T,class U>
void HeapSort<T,U>::HeapIncreaseKey(int i, T key){
	if (cmp()(arr[i],key) && i != arr.size()-1){
		std::cout << "new key is smaller than current key" << std::endl;
	}
	arr[i] = key;
	while(i > 0 && cmp()(arr[i],arr[PARENT(i)])){
		std::swap(arr[i],arr[PARENT(i)]);
		i = PARENT(i);
	}
}


template <class T,class U>
void HeapSort<T,U>::Heapify(int i,int heapsize){
	int l = LEFT(i);
	int r = RIGHT(i);
	int v;
	
	if (l < heapsize && cmp()(arr[l],arr[i])){
		v = l;
	}else v = i;
	if (r < heapsize && cmp()(arr[r],arr[v])){
		v = r;
	}
	if (v != i){
		std::swap(arr[i],arr[v]);
		Heapify(v,heapsize); 
	}
}

template <class T,class U>
void HeapSort<T,U>::show_tree(){
	vector<T> test(1);
	test.insert(test.end(),arr.begin(),arr.end());
	TreeTextHelper::showTree<T>(test);
	cout << endl;
}

template <class T,class U>
void HeapSort<T,U>::show_list(bool asLine){
	for(int i = 0 ; i < arr.size();i++){
		std::cout << arr[i] << " " << (asLine? "\n" : "");
	}
	if (!asLine)std::cout << std::endl;
}


template <class T,class U>
void HeapSort<T,U>::HeapDelete(int i){
	int heapsize = arr.size();
	if (cmp()(arr[i],arr[heapsize-1])){
		arr[i] = arr[heapsize-1];
		Heapify(i,heapsize);
	}
	else{
		HeapIncreaseKey(i,arr[heapsize-1]);
	}
	arr.resize(heapsize-1); // remove the last element
}


template <class T,class U>
void HeapSort<T,U>::HeapInsert(T key){
	arr.resize(arr.size()+1);
	//A[A.heap-size] = -\inf
	HeapIncreaseKey(arr.size()-1,key);
}

//back track algorithm
template <class T,class U>
int HeapSort<T,U>::find_target(T &data,int current){
	if (current >= arr.size()) return -1;
	if (arr[current] == data) return current;
	int left = -1,right = -1;
	
	if (cmp()(arr[LEFT(current)],data) || arr[LEFT(current)] == data) left = find_target(data,LEFT(current));
	if (cmp()(arr[RIGHT(current)],data) || arr[RIGHT(current)] == data) right = find_target(data,RIGHT(current));
	return std::max(left,right); // return the max for less heapify operation
}

template <class T,class U>
void HeapSort<T,U>::HeapDeleteElement(T &obj){
	int find = find_target(obj,0);
	std::cout << find << std::endl;
	if (find == -1) return;//not found
	//then delete
	HeapDelete(find);
	
}


template <class T,class U>
T HeapSort<T,U>::HeapExtract(){
	if (arr.size() == 0) {
		std::cout << "heap underflow" << std::endl;
	}
	T out = arr[0];
	arr[0] = arr[arr.size()-1];
	arr.resize(arr.size()-1);
	Heapify(0,arr.size());
	return out;
}

template <class T,class U>
T HeapSort<T,U>::Top(){
	return arr[0];
}


template <class T,class U>
bool HeapSort<T,U>::empty(){
	return arr.size() == 0;
}





