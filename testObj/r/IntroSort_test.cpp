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

template <typename T>
bool checkSorted(vector<T>& data) {
    for (size_t i = 1; i < data.size(); i++) {
        if (data[i - 1] > data[i]) {
            return false;
        }
    }
    return true;
}

vector<long long int> lmao(vector<DataSet> ds){
    vector<long long int> wtf;
    for(DataSet &f:ds){
        wtf.push_back(f.val);
    }
    return wtf;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	CTimer::init();
	ExcelReader rd("metadata.csv");
	CSVDataSet dataSet;
	rd.readAsCSVDataSet(dataSet,0);
	
	vector<SortData<DataSet>> fastDataSet = SortData<DataSet>::createData(dataSet.dataSet);
	cout << "loaded" << endl;
	vector<long long int> a = lmao(dataSet.dataSet);
	IntroSort<long long int> fast(a);
	CTimer::calc([&](){
		fast.Sort();
	});
	cout << checkSorted(fast.arr) << endl;
	IntroSort<SortData<DataSet>> is2(fastDataSet);
	CTimer::calc([&](){
		is2.Sort();
	});
	
	cout << checkSorted(is2.arr) << endl;
	
	
	
	IntroSort<DataSet> is(dataSet.dataSet);
	CTimer::calc([&](){
		is.Sort();
	});
	cout << checkSorted(is.arr) << endl;
	
	CTimer::calc([&](){
		sort(a.begin(),a.end());
	});
	cout << checkSorted(a) << endl;
	
}
