#include "../Sorting/everything.h"
#include "../Utils/CTimer.cpp"

#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <iostream>
template <class T>
class ExcelReader{
	private:
		ifstream excelFile;
	public:
		ExcelReader(string fileName);
		void readAsObjectVector(vector<T> &outputVector);
	
};
template <class T>
ExcelReader<T>::ExcelReader(string filename){
	excelFile.open(filename,ifstream::in);
}

template <class T>
void ExcelReader<T>::readAsObjectVector(vector<T> &outputObj){
	string line, field;
	vector<vector<string>> array;
	vector<string> v;
	bool skipName = true;
	while(getline(excelFile,line)){
		v.clear();
		stringstream str(line);
		while(getline(str,field,',')){
			v.push_back(field);
		}
		if (skipName){
			skipName = false;
			continue;
		}
		outputObj.push_back(stoull(v[4]));
		array.push_back(v);
	}
}


#include <iostream>
#include <ostream>
using namespace std;

unsigned long long int conv(string s){
	unsigned long long int u = 0;
	for(int i = 0 ; i < s.size();i++){
		u = u * 10 + s[i]-'0';
	}
	return u;
}

template <typename T>
int partition(vector<T> &A, int p, int r) {
    T x = A[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (A[j] < x || A[j] == x) {
            i = i + 1;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[r]);
    return i + 1;
}
template <typename T>
void quicksort(vector<T> &A, int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quicksort(A, p, q - 1);
        quicksort(A, q + 1, r);
    }
}
template <typename T>
void Quick_Sort(vector<T> &arr) {
    quicksort(arr, 0, arr.size() - 1);
}




int main(){
	CTimer::init();
	ExcelReader<long long int> rd("1000000 Sales Records.csv");
	
	vector<long long int> file;
	rd.readAsObjectVector(file);
	
	cout << "data:" << file.size() << endl;
	
//	cout << "InsertionSort:";
//	InsertionSort<DataSet,greater<DataSet>> is(file);
//	
//	CTimer::start_timer();
//	is.Sort();
//	CTimer::stop_timer();
//	cout << CTimer::getFormat() << endl;
	
	cout << "MergeSort(recursion):";
	MergeSort<long long int> ms(file);
	
	CTimer::start_timer();
	ms.Sort();
	CTimer::stop_timer();
	
	//ms.show_list(true);
	cout << CTimer::getFormat() << endl;
	
	cout << "QuickSort(pivot right):";
	QuickSort<long long int> qs(file);
	
	CTimer::start_timer();
	qs.Sort();
	CTimer::stop_timer();
	
	cout << CTimer::getFormat() << endl;
	
	cout << "QuickSort(median of three):";
	QuickSort<long long int> qs2(file);
	
	CTimer::start_timer();
	qs2.SortWithMedianOfThree();
	CTimer::stop_timer();
	
	cout << CTimer::getFormat() << endl;
	
	cout << "HeapSort:";
	HeapSort<long long int> hs(file);
	
	CTimer::start_timer();
	hs.Sort();
	CTimer::stop_timer();
	
	//hs.show_list(true);
	cout << CTimer::getFormat() << endl;
	
	
	
	CTimer::start_timer();
	Quick_Sort(file);
	CTimer::stop_timer();
	cout << CTimer::getFormat() << endl;
	
	
}
