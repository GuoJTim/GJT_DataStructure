#include <bits/stdc++.h>
using namespace std;

int parent(int i) {
	return i/2;
}
int left(int i){
	return i*2;
}
int right(int i){
	return i*2+1;
}

void MAX_HEAPIFY(vector<int> &A,int i,int heapsize){
	int l = left(i);
	int r = right(i);
	int largest;
	if (l <= heapsize && A[l] > A[i]){
		largest = l;
	}else largest = i;
	if (r <= heapsize && A[r] > A[largest]){
		largest = r; 
	}
	if (largest != i){
		swap(A[i],A[largest]);
		MAX_HEAPIFY(A,largest,heapsize);
	}
}

void BUILD_MAX_HEAP(vector<int> &A){
	for (int i = (A.size())/2 ; i >= 1 ; i--){
		MAX_HEAPIFY(A,i,A.size()-1);
	}
}

void HEAPSORT(vector<int> &A){
	A.insert(A.begin(),0);
	int heapsize = A.size()-1;
	BUILD_MAX_HEAP(A);
	for (int i = A.size()-1 ; i >= 2 ; i--){
		swap(A[1],A[i]);
		heapsize = heapsize - 1;
		MAX_HEAPIFY(A,1,heapsize);
	}
	A.erase(A.begin());
}

int main(){
	vector<int> data = {9, 4, 1, 6, 7, 3, 8, 2, 5};
	HEAPSORT(data);
	for(int i : data) cout << i << " ";
}
