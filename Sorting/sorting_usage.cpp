#include "HeapSort.h" 
#include "InsertionSort.h" 
#include "QuickSort.h" 
#include "MergeSort.h" 
#include "../Utils/CTimer.cpp"
#include <iostream>
#include <vector>
using namespace std;
#define DEBUG_LIST


int partition(vector<int> &arr,int p,int r){
	int x = arr[p]; // pivot
	int i = p;
	for(int j = p+1 ; j <= r ;j++){
		if(arr[j] <= x){
			i = i + 1;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i],arr[p]);
	return i;
}




int main(){
	CTimer::init();
	TreeTextHelper::changeElementSize(3);
	vector<int> arr({
		4,50,34,40,22,54,94,3,94,38,8,95,0,36,54,54,81,30,24,98,12,25,43,0,52,52,88,22,83,70,96,57,89,53,13,64,74,18,37,86,73,76,15,1,93,69,77,81,29,78,14,45,67,1,0,41,60,63,74,16,75,75,36,49,68,5,67,29,15,84,47,77,40,80,24,61,25,7,85,83,81,47,10,39,22,72,87,64,92,27,50,69,12,54,23,85,38,75,73,94
	});
	HeapSort<int> hs(arr);
	while(!hs.empty()){
		cout << hs.HeapExtract() << endl;
	}
//	cout << "HeapSort" << endl;
//	CTimer::start_timer();
//	hs.Sort();
//	CTimer::stop_timer();
//	cout << CTimer::getFormat() << endl;
#ifdef DEBUG_LIST
	hs.show_list();
#endif
	
	InsertionSort<int> is(arr);
	cout << "InsertionSort" << endl;
	CTimer::start_timer();
	is.Sort();
	CTimer::stop_timer();
	cout << CTimer::getFormat() << endl;
#ifdef DEBUG_LIST
	is.show_list();
#endif
	
	
	QuickSort<int> qs(arr);
	cout << "QuickSort (right pivot)" << endl;
	CTimer::start_timer();
	qs.Sort();
	CTimer::stop_timer();
	cout << CTimer::getFormat() << endl;
#ifdef DEBUG_LIST
	qs.show_list();
#endif
	
		
	QuickSort<int> qs2(arr);
	cout << "QuickSort (custom pivot)" << endl;
	CTimer::start_timer();
	qs2.Sort(&partition);
	CTimer::stop_timer();
	cout << CTimer::getFormat() << endl;
#ifdef DEBUG_LIST
	qs2.show_list();
#endif
	
	
	QuickSort<int> qs3(arr);
	cout << "QuickSort (median of three)" << endl;
	CTimer::start_timer();
	qs3.SortWithMedianOfThree();
	CTimer::stop_timer();
	cout << CTimer::getFormat() << endl;
#ifdef DEBUG_LIST
	qs3.show_list();
#endif
	
	
	MergeSort<int> ms(arr);
	cout << "MergeSort (recursion)" << endl;
	CTimer::start_timer();
	ms.Sort();
	CTimer::stop_timer();
	cout << CTimer::getFormat() << endl;
#ifdef DEBUG_LIST
	ms.show_list();
#endif

	HeapSort<int> test;
	test.Sort(arr);
	for(int i :arr) cout << i << " ";

	
}
