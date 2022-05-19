#include "HeapSort.h"
#include <iostream>
template <class T,class U>
HeapSort<T,U>::HeapSort(std::vector<T> &arr){
	this->arr = arr;
	//for (T& obj:arr){
	//	HeapInsert(obj);	
	//}
}
template <class T,class U>
HeapSort<T,U>::HeapSort(){

}

template <class T,class U>
void HeapSort<T,U>::Sort(std::vector<T> &arr,int begin,int end){
	BuildHeap(arr);
	for (int i = end ; i>= begin ; i--){
		std::swap(arr[begin],arr[i]);
		Heapify(arr,begin,i);
	}
}

template <class T,class U>
void HeapSort<T,U>::Sort(){
	Sort(arr);
}
template <class T,class U>
void HeapSort<T,U>::Sort(std::vector<T> &arr){
	Sort(arr,0,arr.size()-1);
}

template <class T,class U>
void HeapSort<T,U>::BuildHeap(std::vector<T> &arr){
	int size = arr.size();//get size
	for (int i = (size / 2 - 1) ; i >= 0 ; i--){
		Heapify(arr,i,size);
	}
}

template <class T,class U>
void HeapSort<T,U>::HeapIncreaseKey(std::vector<T> &arr,int i, T &key){
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
void HeapSort<T,U>::Heapify(std::vector<T> &arr,int i,int heapsize){
	int l = LEFT(i);
	int r = RIGHT(i);
	int v;
	
	if (l < heapsize && cmp()(arr[i],arr[l])){
		v = l;
	}else v = i;
	if (r < heapsize && cmp()(arr[v],arr[r])){
		v = r;
	}
	if (v != i){
		
		T t = arr[i];
		arr[i] = arr[v];
		arr[v] = t;
		Heapify(arr,v,heapsize); 
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
void HeapSort<T,U>::HeapDelete(std::vector<T> &arr,int i){
	int heapsize = arr.size();
	if (cmp()(arr[heapsize-1],arr[i])){
		arr[i] = arr[heapsize-1];
		Heapify(arr,i,heapsize);
	}
	else{
		HeapIncreaseKey(arr,i,arr[heapsize-1]);
	}
	arr.resize(heapsize-1); // remove the last element
}


template <class T,class U>
void HeapSort<T,U>::HeapInsert(std::vector<T> &arr,T& key){
	arr.resize(arr.size()+1);
	//A[A.heap-size] = -\inf
	HeapIncreaseKey(arr,arr.size()-1,key);
}

template <class T,class U>
void HeapSort<T,U>::HeapInsert(T& key){
	HeapInsert(arr,key);
}

//back track algorithm
template <class T,class U>
int HeapSort<T,U>::find_target(std::vector<T> &arr,T &data,int current){
	if (current >= arr.size()) return -1;
	if (arr[current] == data) return current;
	int left = -1,right = -1;
	
	if (cmp()(data,arr[LEFT(current)]) || arr[LEFT(current)] == data) left = find_target(arr,data,LEFT(current));
	if (cmp()(data,arr[RIGHT(current)]) || arr[RIGHT(current)] == data) right = find_target(arr,data,RIGHT(current));
	return std::max(left,right); // return the max for less heapify operation
}

template <class T,class U>
void HeapSort<T,U>::HeapDeleteElement(std::vector<T> &arr,T &obj){
	int find = find_target(arr,obj,0);
	std::cout << find << std::endl;
	if (find == -1) return;//not found
	//then delete
	HeapDelete(arr,find);
}

template <class T,class U>
void HeapSort<T,U>::HeapDeleteElement(T &obj){
	HeapDeleteElement(arr,obj);
}


template <class T,class U>
T HeapSort<T,U>::HeapExtract(std::vector<T> &arr){
	if (arr.size() == 0) {
		std::cout << "heap underflow" << std::endl;
	}
	T out = arr[0];
	arr[0] = arr[arr.size()-1];
	arr.resize(arr.size()-1);
	Heapify(arr,0,arr.size());
	return out;
}

template <class T,class U>
T HeapSort<T,U>::HeapExtract(){
	return HeapExtract(arr);
}

template <class T,class U>
T HeapSort<T,U>::Top(std::vector<T> &arr){
	return arr[0];
}
template <class T,class U>
T HeapSort<T,U>::Top(){
	return Top(arr);
}


template <class T,class U>
bool HeapSort<T,U>::empty(std::vector<T> &arr){
	return arr.size() == 0;
}

template <class T,class U>
bool HeapSort<T,U>::empty(){
	return empty(arr);
}





