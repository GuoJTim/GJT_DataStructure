#include "../Sorting/everything.h"
#include "../Sorting/SortData.h"
#include "../Utils/CTimer.cpp"
#include "../Utils/ExcelReader.h"
#include "../Utils/CSVDataSet.cpp"

#include <iostream>
#include <ostream>
using namespace std;

std::ostream& operator<<(std::ostream& os,SortData<DataSet> &obj){
	os << *(obj.pointer);
	return os;
}


vector<long long int> lmao(vector<DataSet> ds){
    vector<long long int> wtf;
    for(DataSet &f:ds){
        wtf.push_back(f.val);
    }
    return wtf;
}

int main(){
	CTimer::init();
	ExcelReader rd("1000000 Sales Records.csv");
	CSVDataSet dataSet;
	rd.readAsCSVDataSet(dataSet,4);
	
	vector<SortData<DataSet>> fastDataSet = SortData<DataSet>::createData(dataSet.dataSet);
	
	vector<long long int> a = lmao(dataSet.dataSet);
	
	HeapSort<long long int> fast(a);
	CTimer::calc([&](){
		fast.Sort();
	});
	
	HeapSort<SortData<DataSet>> is2(fastDataSet);
	CTimer::calc([&](){
		is2.Sort();
	});
	
	
	
	HeapSort<DataSet> is(dataSet.dataSet);
	CTimer::calc([&](){
		is.Sort();
	});
	
	QuickSort<SortData<DataSet>> qs(fastDataSet);
	CTimer::calc([&](){
		qs.SortWithMedianOfThree();
	});
	
	CTimer::calc([&](){
		sort(a.begin(),a.end());
	});
	
	
	
}
