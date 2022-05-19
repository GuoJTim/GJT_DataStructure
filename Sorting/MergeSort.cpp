#include "MergeSort.h"
#include <iostream>

template <class T,class U>
MergeSort<T,U>::MergeSort(std::vector<T> &arr){
	this->arr = arr;
}

template <class T,class U>
MergeSort<T,U>::MergeSort(){

}

template <class T,class U>
void MergeSort<T,U>::mergesort(std::vector<T> &arr,int p,int r){
	if (p < r){
		int q = (p+r) / 2;
		mergesort(arr,p,q);
		mergesort(arr,q+1,r);
		merge(arr,p,q,r);
	}
}

template <class T,class U>
void MergeSort<T,U>::merge(std::vector<T> &arr,int p,int q,int r){
	int n1 = q-p+1;
	int n2 = r-q;
	T *L = new T[n1+1];
	T *R = new T[n2+1];
	
	std::copy(arr.begin()+p,arr.begin()+p+n1,L);
	std::copy(arr.begin()+q+1,arr.begin()+q+1+n2,R);
	//for (int i = 0 ; i < n1 ;i++) L[i] = arr[p+i];
	//for (int i = 0 ; i < n2 ;i++) R[i] = arr[q+i+1];
	
	// limit value
	//L[n1] = 99999;
	//R[n2] = 99999;
	int li = 0;
	int ri = 0;
	
	for(int k = p; k <= r;k++){
		if (li == n1){
			arr[k] = R[ri];
			ri++;
		}else if (ri == n2){
			arr[k] = L[li];
			li++;
		}else if (cmp()(L[li],R[ri])){
			arr[k] = L[li];
			li++;
		}else{
			arr[k] = R[ri];
			ri++;
		}
	}
	delete [] L;
	delete [] R;
}


template <class T,class U>
void MergeSort<T,U>::Sort(std::vector<T> &arr){
	mergesort(arr,0,arr.size()-1);
}

template <class T,class U>
void MergeSort<T,U>::Sort(){
	Sort(arr);
}

template <class T,class U>
void MergeSort<T,U>::show_list(bool asLine){
	for(int i = 0 ; i < arr.size();i++){
		std::cout << arr[i] << " " << (asLine? "\n" : "");
	}
	if (!asLine)std::cout << std::endl;
}
