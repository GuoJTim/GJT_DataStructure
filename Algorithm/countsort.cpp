#include <bits/stdc++.h>
using namespace std;


void counting_sort(vector<int> &A,vector<int> &B,int k){
	vector<int> C(k,0);
	
	for(int i = 0 ; i < A.size();i++) C[A[i]]++;
	for(int i = 1 ; i < k;i++) C[i] = C[i-1]+C[i];
	for(int j = A.size()-1; j >= 0 ; j--){
		B[C[A[j]]-1] = A[j];
		C[A[j]] = C[A[j]] - 1;
	}
}

int main(){
	vector<int> data = {6,7,4,2,1,3,6,4,5};
	vector<int> result(data.size());
	counting_sort(data,result,8);
	for(int i : result) cout << i << " ";
}
