#include <bits/stdc++.h>
using namespace std;


void insertion_sort(vector<int> &A){
	for (int j = 1 ; j < A.size();j++){
		int key = A[j];
		int i = j - 1;
		while(i >= 0 && A[i] > key){
			A[i+1] = A[i];
			i = i - 1;
		}
		A[i+1] = key;
	}
}

int main(){
	vector<int> data = {6,7,4,2,1,3,6,4,5};
	insertion_sort(data);
	for(int i : data) cout << i << " ";
}
