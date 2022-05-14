#include "HeapSort.h" 
#include "InsertionSort.h" 
#include <iostream>
#include <vector>
using namespace std;

int main(){
	TreeTextHelper::changeElementSize(3);
	vector<int> arr({9,5,1,2,3,4,6,7,8,0});
	HeapSort<int> hs(arr);
	hs.HeapInsert(5);
//	while(!hs.empty()){
//		cout << hs.HeapExtract() << endl;
//	}
	hs.Sort();
	hs.show_list();
	
	InsertionSort<int,greater<int>> is(arr,true);
	is.Insert(5);
	is.Sort();
	is.show_list();
}
