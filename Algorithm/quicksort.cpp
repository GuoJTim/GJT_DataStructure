#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &A ,int p,int r);
void quicksort(vector<int> &A,int p,int r){
	if(p < r){
		int q = partition(A,p,r);
		quicksort(A,p,q-1);
		quicksort(A,q+1,r);
	}
}

//int partition(vector<int> &A ,int p,int r){
//	int x = A[r];
//	int i = p-1;
//	for(int j = p ; j < r;j++){
//		if(A[j] <= x){
//			i = i+1;
//			swap(A[i],A[j]);
//		}
//	}
//	swap(A[i+1],A[r]);
//	return i+1;
//}

int partition(vector<int> &A ,int p,int r){
	int x = A[p];
	int i = p;
	for(int j = p+1 ; j <= r ;j++){
		if(A[j] <= x){
			i = i + 1;
			swap(A[i],A[j]);
		}
	}
	swap(A[i],A[p]);
	return i;
}

int main(){
	vector<int> data = {6,7,9,9,9,4,2,0,4,2,1,3,6,4,5};
	quicksort(data,0,data.size()-1);
	for(int i : data) cout << i << " ";
}
