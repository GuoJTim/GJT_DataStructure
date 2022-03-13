#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &A,int p,int q,int r);

void mergesort(vector<int> &A,int p,int r){
	if (p < r){
		int q = (p+r) / 2;
		mergesort(A,p,q);
		mergesort(A,q+1,r);
		merge(A,p,q,r);
	}
}

void merge(vector<int> &A,int p,int q,int r){
	int n1 = q-p+1;
	int n2 = r-q;
	int L[n1+1];
	int R[n2+1];
	
	for (int i = 0 ; i < n1 ;i++) L[i] = A[p+i];
	for (int i = 0 ; i < n2 ;i++) R[i] = A[q+i+1];
	
	L[n1] = 99999;
	R[n2] = 99999;
	int li = 0;
	int ri = 0;
	
	for(int k = p; k <= r;k++){
		if (L[li] < R[ri]){
			A[k] = L[li];
			li++;
		}else{
			A[k] = R[ri];
			ri++;
		}
	}
	
}

int main(){
	vector<int> data = {6,7,4,2,1,3,6,4,5};
	mergesort(data,0,data.size()-1);
	for(int i : data) cout << i << " ";
}
