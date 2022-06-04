#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &A ,int p,int r);
void quicksort(vector<int> &A,int p,int r){
	if(p < r){
		for(int i:A){
			cout << i << " ";
		}
		int q = partition(A,p-1,r-1);
		
		cout << endl;
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

//int partition(vector<int> &A ,int p,int r){
//	int x = A[p];
//	int i = p;
//	for(int j = p+1 ; j <= r ;j++){
//		if(A[j] <= x){
//			i = i + 1;
//			swap(A[i],A[j]);
//		}
//	}
//	swap(A[i],A[p]);
//	return i;
//}

int partition(vector<int> &A ,int left,int right){
	int i = left;
	int j = right;
	int pivot = A[left];
	do{
		do i++;while(A[i] < pivot);
		do j--;while(A[j] < pivot);
		if(i < j)swap(A[i],A[j]);
		
	}while(i < j);
	swap(A[left],A[j]);
}

int main(){
	vector<int> data = {26,5,37,1,61,11,59,15,48,19};
	quicksort(data,0,data.size()-1);
	for(int i : data) cout << i << " ";
}
