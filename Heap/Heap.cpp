#include "Heap.h"
#include "../Utils/TreeTextHelper.cpp"


#include <iostream>
template <class T,class U>
Heap<T,U>::Heap(){	
	arr.push_back(0);
}

template <class T,class U>
Heap<T,U>::Heap(vector<T> _arr){
	
	arr.push_back(0);
	
	for(T data: _arr) Insert(data);
}

template <class T,class U>
void Heap<T,U>::Insert(T data){
	arr.push_back(data);
	int current_index = arr.size()-1;
	while(current_index > 1 && cmp()(arr[current_index],arr[current_index/2])){
		swap(arr[current_index],arr[current_index/2]);
		current_index /=2;
	}
}
template <class T,class U>
T Heap<T,U>::top(){
	return arr[1];
}
template <class T,class U>
T Heap<T,U>::extract(){
	T result = arr[1];
	arr[1] = arr[arr.size()-1];
	arr.pop_back();
	
	heapify(1,arr.size()-1);
	return result;
}
		
template <class T,class U>
void Heap<T,U>::heapify(int i,int heapsize){
	int l = i*2;
	int r = i*2+1;
	int v;
	if (l <= heapsize && cmp()(arr[l],arr[i])){
		v = l;
	}else v = i;
	if (r <= heapsize && cmp()(arr[r],arr[v])){
		v = r;
	}
	if (v != i){
		swap(arr[i],arr[v]);
		heapify(v,heapsize); 
	}
}
		
template <class T,class U>
void Heap<T,U>::build_heap(){
	for (int i = arr.size()/2 ; i >= 1;i--){
		heapify(i,arr.size()-1);
	}
}

template <class T,class U>
int Heap<T,U>::size(){
	return arr.size()-1;
}

template <class T,class U>
void Heap<T,U>::Sort(){		
	build_heap();
	int heapsize = arr.size()-1;
	for(int i = arr.size()-1 ; i >= 2 ;i-- ){
		swap(arr[1],arr[i]); 
		heapsize -= 1;
		heapify(1,heapsize);
	}
}  

template <class T,class U>
void Heap<T,U>::show_list(){
	for(int i = 1 ; i < arr.size();i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}
		
template <class T,class U>
void Heap<T,U>::show_tree(){
	TreeTextHelper::showTree<T>(arr);
	cout << endl;
}

template <class T,class U>
void Heap<T,U>::sequence_order(){
	for(int i = 1 ; i < arr.size();i++){
		cout << arr[i] << " ";
	}
}


//back track algorithm
template <class T,class U>
int Heap<T,U>::find_target(T &data,int current){
	if (current >= arr.size()) return -1;
	if (arr[current] == data) return current;
	int left = -1,right = -1;
	
	if (cmp()(arr[current*2],data) || arr[current*2] == data) left = find_target(data,current*2);
	if (cmp()(arr[current*2+1],data) || arr[current*2+1] == data) right = find_target(data,current*2+1);
	return max(left,right); // return the max for less heapify operation
}

template <class T,class U>
void Heap<T,U>::Delete(T data){
	//delete a data
	int current = 1;//root
	int index = find_target(data,current);
	if (index == -1) {
		cout << "wtf not found" << endl; 
		return; //not found
	}else{// do heapify
		current = index;
		arr[current] = arr.back();// can use the last element to swap
		arr.pop_back();// remove back
		heapify(current,arr.size());
		while(current > 1 && cmp()(arr[current],arr[current/2])){
			swap(arr[current],arr[current/2]);
			current /=2;
		}
	}
}
