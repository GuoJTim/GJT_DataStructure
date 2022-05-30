#include "../Utils/CTimer.cpp"
#include "../Utils/ExcelReader.h"

#include <iostream>
#include <ostream>
#include <ctime>
#include <cmath>
using namespace std;

unsigned long long int conv(string s){
	unsigned long long int u = 0;
	for(int i = 0 ; i < s.size();i++){
		u = u * 10 + s[i]-'0';
	}
	return u;
}
class DataSet{
	public:
		string Region;
		string Item_Type;
		string Order_Prior;
		string Order_Date;
		unsigned long long Orider_ID;
		DataSet(){
			//for heap sort init
		}
		DataSet(vector<string> obj){
			Region = obj[0];
			Item_Type = obj[1];
			Order_Prior = obj[2];
			Order_Date = obj[3];
			Orider_ID = conv(obj[4]);
		}
		bool operator>(const DataSet& a) const{
			return this->Orider_ID > a.Orider_ID;
		}
		bool operator<(const DataSet& a) const{
			return this->Orider_ID < a.Orider_ID;
		}
		bool operator==(const DataSet& a) const{
			return this->Orider_ID == a.Orider_ID;
		}
		
		friend std::ostream& operator<<(std::ostream& ,DataSet&); // for cout
};

ostream& operator<<(ostream& os,DataSet &obj){
	os << obj.Orider_ID;
	return os;
}



template <class T>
void HeapSort(vector<T> &arr){
	int size = arr.size();//get size
	for (int i = (size / 2 - 1) ; i >= 0 ; i--){
		Heapify(arr,i,size);
	}
	for (int i = size - 1 ; i>= 0 ; i--){
		std::swap(arr[0],arr[i]);
		Heapify(arr,0,i);
	}
}


template <class T>
void Heapify(vector<T> &arr,int i,int heapsize){
	int l = i*2+1;
	int r = i*2+2;
	int v;
	
	if (l < heapsize && arr[l] < arr[i]){
		v = l;
	}else v = i;
	if (r < heapsize &&  arr[r]<arr[v] ){
		v = r;
	}
	if (v != i){
		std::swap(arr[i],arr[v]);
		Heapify(arr,v,heapsize); 
	}
}





template <typename T>
void heapify(std::vector<T>& arr, int size, int i) {
	int largest = i;           // Initialize largest as root
	int left = (i << 1) | 1;   // left = 2*i+1
	int right = (i << 1) + 2;  // right = 2*i+2

	if (left < size && arr[left] > arr[largest])
		largest = left;
	if (right < size && arr[right] > arr[largest])
		largest = right;
	if (largest != i) {
		std::swap(arr[i], arr[largest]);
		// Recursively heapify the affected sub-tree
		heapify(arr, size, largest);
	}
}

template <typename T>
void Heap_Sort(std::vector<T>& arr) {
	// Build heap (rearrange array)
	for (int i = arr.size() / 2 - 1; i >= 0; i--)
		heapify(arr, arr.size(), i);

	// One by one extract an element from heap
	for (int i = arr.size() - 1; i > 0; i--) {
		// Move current root to end
		std::swap(arr[0], arr[i]);
		// call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
}





int main(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	CTimer::init();
	ExcelReader<DataSet> rd("1000000 Sales Records.csv");
	
	clock_t  time_dis;
	
	vector<DataSet> file;
	rd.readAsObjectVector(file);
	vector<DataSet> f(file);
	cout << "data:" << file.size() << endl;	
	
	time_dis = clock();
	HeapSort<DataSet>(f);
	time_dis = clock()-time_dis;	
	cout << (float)time_dis/CLOCKS_PER_SEC << endl;
	
	f = vector<DataSet> (file);
	time_dis = clock();
	Heap_Sort<DataSet>(f);
	time_dis = clock()-time_dis;	
	cout << (float)time_dis/CLOCKS_PER_SEC << endl;
	
	
}
