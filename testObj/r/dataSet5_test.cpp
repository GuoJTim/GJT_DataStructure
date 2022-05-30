#include "../Sorting/everything.h"
#include "../Sorting/SortData.h"
#include "../Utils/CTimer.cpp"
#include "../Utils/ExcelReader.h"

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

class DataSet{
	public:
		string confirmation_num;
		unsigned long long bbl;
		string lab_name;
		string nta;
		DataSet(){
			//for heap sort init
		}
		DataSet(vector<string> obj){
			confirmation_num = obj[0];
			bbl = conv(obj[1]);
			lab_name = obj[2];
			nta = obj[3];
		}
		bool operator>(const DataSet& a) const{
			return this->bbl > a.bbl;
		}
		bool operator<(const DataSet& a) const{
			return this->bbl < a.bbl;
		}
		bool operator==(const DataSet& a) const{
			return this->bbl == a.bbl;
		}
		
		friend std::ostream& operator<<(std::ostream& ,DataSet&); // for cout
};


std::ostream& operator<<(std::ostream& os,SortData<DataSet> &obj){
	os << *obj.pointer;
	return os;
}

ostream& operator<<(ostream& os,DataSet &obj){
	os << obj.confirmation_num << " " << obj.bbl << " " << obj.lab_name << " " << obj.nta;
	return os;
}




int main(){
	CTimer::init();
	ExcelReader<DataSet> rd("rooftop-drinking-water-tank-inspection-results.csv");
	
	vector<DataSet> file;
	rd.readAsObjectVector(file);
	
	vector<SortData<DataSet>> fadeFile;
	fadeFile = SortData<DataSet>::createData(file);
	cout << "data:" << fadeFile.size() << endl;
	
	cout << "InsertionSort:";
	InsertionSort<DataSet,greater<DataSet>> is(file);
	cout << endl;cout << endl;
	CTimer::start_timer();
	is.Sort();
	CTimer::stop_timer();
	cout << CTimer::getFormat() << endl;
	
	return 0 ;
	
	cout << "MergeSort(recursion):";
	MergeSort<SortData<DataSet>> ms(fadeFile);
	
	CTimer::start_timer();
	ms.Sort();
	CTimer::stop_timer();
	
	//ms.show_list(true);
	cout << CTimer::getFormat() << endl;
	
	cout << "QuickSort(pivot right):";
	QuickSort<SortData<DataSet>> qs(fadeFile);
	
	CTimer::start_timer();
	qs.Sort();
	CTimer::stop_timer();
	
	cout << CTimer::getFormat() << endl;
	
	cout << "QuickSort(median of three):";
	QuickSort<SortData<DataSet>> qs2(fadeFile);
	
	CTimer::start_timer();
	qs2.SortWithMedianOfThree();
	CTimer::stop_timer();
	
	cout << CTimer::getFormat() << endl;
	
	cout << "HeapSort:";
	HeapSort<SortData<DataSet>> hs(fadeFile);
	
	cout << "start timer:";
	CTimer::start_timer();
	hs.Sort();
	CTimer::stop_timer();
	
	//hs.show_list(true);
	cout << CTimer::getFormat() << endl;
	
	
	hs.show_list(true);
	
	
	CTimer::start_timer();
	Quick_Sort(fadeFile);
	CTimer::stop_timer();
	cout << CTimer::getFormat() << endl;
	
	
}
