#include "HeapSort.h"
#include "InsertionSort.h"
#include "../Utils/CTimer.cpp"
#include <iostream>
using namespace std;
int main(){
	vector<int> arr({
		1,9,2,8,3,7,4,6
	});
	
	InsertionSort<int> test;
	CTimer::calc([&](){
		test.Sort(arr,1,2);
	});
	for(int i : arr) cout << i << " ";
	cout << endl;
	arr = vector<int>({
		1,9,2,8,3,7,4,6
	});
	HeapSort<int> test2;
	CTimer::calc([&](){
		test2.Sort(arr,1,2);
	});
	for(int i : arr) cout << i << " ";
}