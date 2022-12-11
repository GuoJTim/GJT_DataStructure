#include "../Sorting/everything.h"
#include "../Sorting/SortData.h"
#include "../Utils/CTimer.h"
#include "../Utils/ExcelReader.h"
#include "../Utils/CSVDataSet.cpp"
#include "../Utils/RandomShuffle.h"

#define FULLDATA
#define PTRDATA
#define ONLYNUM
#include <stdlib.h>
#include <iostream>
#include <ostream>
using namespace std;

template <typename T>
bool checkSorted(vector<T>& data) {
    for (size_t i = 1; i < data.size(); i++) {
        if (data[i - 1] > data[i]) {
            return false;
        }
    }
    return true;
}

std::ostream& operator<<(std::ostream& os,SortData<DataSet> &obj){
	os << *(obj.pointer);
	return os;
}

vector<long long int> toLLvec(vector<DataSet> ds){
    vector<long long int> ret;
    for(DataSet &f:ds){
        ret.push_back(f.val);
    }
    return ret;
}


void solve(string fileName,int sortHeader){
	ExcelReader rawFile(fileName);
	CSVDataSet csvDataSet;
	vector<SortData<DataSet>> ptrDataSet;
	cout << "Loading DataSets...(" << fileName << ")" << endl;
	CTimer::calc([&](){
		rawFile.readAsCSVDataSet(csvDataSet,sortHeader);
		RandomShuffle::arr_shuffle(csvDataSet.dataSet);	
		ptrDataSet = SortData<DataSet>::createData(csvDataSet.dataSet);
		RandomShuffle::arr_shuffle(ptrDataSet);
	},"Loaded data ,spents %f second(s).\n");
	
	
	cout << "STLSort:" << endl;
	vector<SortData<DataSet>> unordered_ptr_arr(ptrDataSet);
	CTimer::calc([&](){
		sort(unordered_ptr_arr.rbegin(),unordered_ptr_arr.rend());
	},"\t(PTRDATA) spents %f second(s).");
	if (checkSorted(unordered_ptr_arr)) cout << "\t|Sorted - (O)" << endl;
	else cout << "\t|Sorted - (X)" << endl;
	cout << "pre 5" << endl;
	for (int i = 0 ; i < 5 ; i++){
		cout << unordered_ptr_arr[i] << endl;
	}
	cout << "suf 5" << endl;
	for(int i = csvDataSet.dataSet.size()-5; i < csvDataSet.dataSet.size();i++){
		cout << unordered_ptr_arr[i] << endl;
	}

	cout << "HeapSort:" << endl;
	HeapSort<SortData<DataSet>,greater<SortData<DataSet>>> hs2(ptrDataSet);
	CTimer::calc([&](){
		hs2.Sort();
	},"\t(PTRDATA) spents %f second(s).");
	if (checkSorted(hs2.arr)) cout << "\t|Sorted - (O)" << endl;
	else cout << "\t|Sorted - (X)" << endl;
	cout << "pre 5" << endl;
	for (int i = 0 ; i < 5 ; i++){
		cout << hs2.arr[i] << endl;
	}
	cout << "suf 5" << endl;
	for(int i = csvDataSet.dataSet.size()-5; i < csvDataSet.dataSet.size();i++){
		cout << hs2.arr[i] << endl;
	}


	cout << "(Recursive)MergeSort:" << endl;
	MergeSort<SortData<DataSet>,greater<SortData<DataSet>>> ms2(ptrDataSet);
	CTimer::calc([&](){
		ms2.Sort();
	},"\t(PTRDATA) spents %f second(s).");
	if (checkSorted(ms2.arr)) cout << "\t|Sorted - (O)" << endl;
	else cout << "\t|Sorted - (X)" << endl;
	cout << "pre 5" << endl;
	for (int i = 0 ; i < 5 ; i++){
		cout << ms2.arr[i] << endl;
	}
	cout << "suf 5" << endl;
	for(int i = csvDataSet.dataSet.size()-5; i < csvDataSet.dataSet.size();i++){
		cout << ms2.arr[i] << endl;
	}
	

	cout << "(Iterative)MergeSort:" << endl;
	MergeSort<SortData<DataSet>,greater<SortData<DataSet>>> msi2(ptrDataSet);
	CTimer::calc([&](){
		msi2.IterativeSort();
	},"\t(PTRDATA) spents %f second(s).");
	if (checkSorted(msi2.arr)) cout << "\t|Sorted - (O)" << endl;
	else cout << "\t|Sorted - (X)" << endl;
	cout << "pre 5" << endl;
	for (int i = 0 ; i < 5 ; i++){
		cout << msi2.arr[i] << endl;
	}
	cout << "suf 5" << endl;
	for(int i = csvDataSet.dataSet.size()-5; i < csvDataSet.dataSet.size();i++){
		cout << msi2.arr[i] << endl;
	}
	
	cout << "QuickSort:" << endl;
	QuickSort<SortData<DataSet>,greater<SortData<DataSet>>> qs2(ptrDataSet);
	CTimer::calc([&](){
		qs2.Sort();
	},"\t(PTRDATA) spents %f second(s).");
	if (checkSorted(qs2.arr)) cout << "\t|Sorted - (O)" << endl;
	else cout << "\t|Sorted - (X)" << endl;
	cout << "pre 5" << endl;
	for (int i = 0 ; i < 5 ; i++){
		cout << qs2.arr[i] << endl;
	}
	cout << "suf 5" << endl;
	for(int i = csvDataSet.dataSet.size()-5; i < csvDataSet.dataSet.size();i++){
		cout << qs2.arr[i] << endl;
	}


	cout << "IntroSort:" << endl;
	IntroSort<SortData<DataSet>,greater<SortData<DataSet>>> its2(ptrDataSet);
	CTimer::calc([&](){
		its2.Sort();
	},"\t(PTRDATA) spents %f second(s).");
	if (checkSorted(its2.arr)) cout << "\t|Sorted - (O)" << endl;
	else cout << "\t|Sorted - (X)" << endl;
	cout << "pre 5" << endl;
	for (int i = 0 ; i < 5 ; i++){
		cout << its2.arr[i] << endl;
	}
	cout << "suf 5" << endl;
	for(int i = csvDataSet.dataSet.size()-5; i < csvDataSet.dataSet.size();i++){
		cout << its2.arr[i] << endl;
	}

	
	
	cout << "InsertionSort:" << endl;
	InsertionSort<SortData<DataSet>,greater<SortData<DataSet>>> is2(ptrDataSet);
	CTimer::calc([&](){
		is2.Sort();
	},"\t(PTRDATA) spents %f second(s).");
	if (checkSorted(is2.arr)) cout << "\t|Sorted - (O)" << endl;
	else cout << "\t|Sorted - (X)" << endl;
	cout << "pre 5" << endl;
	for (int i = 0 ; i < 5 ; i++){
		cout << is2.arr[i] << endl;
	}
	cout << "suf 5" << endl;
	for(int i = csvDataSet.dataSet.size()-5; i < csvDataSet.dataSet.size();i++){
		cout << is2.arr[i] << endl;
	}
	
	
}



int main(){
	CTimer::init();
	solve("rooftop-drinking-water-tank-inspection-results.csv",1);
	cout << endl;cout << endl;
//	solve("metadata.csv",0);
//	cout << endl;cout << endl;
//	solve("1000000 Sales Records.csv",4);
//	cout << endl << endl;
	return 0;	
}
