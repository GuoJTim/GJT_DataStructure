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

int main(){
	CTimer::init();
	ExcelReader rd("1000000 Sales Records.csv");
	CSVDataSet dataSet;
	rd.readAsCSVDataSet(dataSet,4);
	
	vector<SortData<DataSet>> fastDataSet = SortData<DataSet>::createData(dataSet.dataSet);
	
	
	InsertionSort<SortData<DataSet>> is2(fastDataSet);
	CTimer::calc([&](){
		is2.Sort();
	});
	
	
	
	InsertionSort<DataSet> is(dataSet.dataSet);
	CTimer::calc([&](){
		is.Sort();
	});
	
	
	
	
}
