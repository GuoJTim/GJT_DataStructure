#include "../Sorting/everything.h"
#include "../Sorting/SortData.h"
#include "../Utils/CTimer.h"
#include "../Utils/ExcelReader.h"
#include "../Utils/CSVDataSet.cpp"
#include "../Utils/RandomShuffle.h"

//#define FULLDATA
//#define PTRDATA
#define ONLYNUM

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
#ifdef PTRDATA
	vector<SortData<DataSet>> ptrDataSet;
#endif
#ifdef ONLYNUM
	vector<long long int> LLds;
#endif
	cout << "Loading DataSets...(" << fileName << ")" << endl;
	CTimer::calc([&](){
		rawFile.readAsCSVDataSet(csvDataSet,sortHeader);
		RandomShuffle::arr_shuffle(csvDataSet.dataSet);
#ifdef PTRDATA		
		ptrDataSet = SortData<DataSet>::createData(csvDataSet.dataSet);
		RandomShuffle::arr_shuffle(ptrDataSet);
#endif
#ifdef ONLYNUM
		LLds = toLLvec(csvDataSet.dataSet);
		RandomShuffle::arr_shuffle(LLds);
#endif
	},"Loaded data ,spents %f second(s).\n");
	
	
	cout << "STLSort:" << endl;
#ifdef FULLDATA
	vector<DataSet> unordered_arr(csvDataSet.dataSet);
	CTimer::calc([&](){
		sort(unordered_arr.begin(),unordered_arr.end());
	},"\t(FULLDATA) spents %f second(s).");
	if (checkSorted(unordered_arr)) cout << "\t|Sorted - (O)" << endl;
	else cout << "\t|Sorted - (X)" << endl;
#endif
#ifdef PTRDATA	
	vector<SortData<DataSet>> unordered_ptr_arr(ptrDataSet);
	CTimer::calc([&](){
		sort(unordered_ptr_arr.begin(),unordered_ptr_arr.end());
	},"\t(PTRDATA) spents %f second(s).");
	if (checkSorted(unordered_ptr_arr)) cout << "\t|Sorted - (O)" << endl;
	else cout << "\t|Sorted - (X)" << endl;
#endif
#ifdef ONLYNUM
	vector<long long int> unordered_LL_arr(LLds);
	CTimer::calc([&](){
		sort(unordered_LL_arr.begin(),unordered_LL_arr.end());	
	},"\t(ONLYNUM) spents %f second(s).");
	if (checkSorted(unordered_LL_arr)) cout << "\t|Sorted - (O)" << endl;
	else cout << "\t|Sorted - (X)" << endl;
#endif

	cout << "HeapSort:" << endl;
#ifdef FULLDATA
	HeapSort<DataSet> hs1(csvDataSet.dataSet);
	CTimer::calc([&](){
		hs1.Sort();
	},"\t(FULLDATA) spents %f second(s).");
	if (checkSorted(hs1.arr)) cout << "\t|Sorted - (O)" << endl;
	else cout << "\t|Sorted - (X)" << endl;
#endif
#ifdef PTRDATA	
	HeapSort<SortData<DataSet>> hs2(ptrDataSet);
	CTimer::calc([&](){
		hs2.Sort();
	},"\t(PTRDATA) spents %f second(s).");
	if (checkSorted(hs2.arr)) cout << "\t|Sorted - (O)" << endl;
	else cout << "\t|Sorted - (X)" << endl;
#endif
#ifdef ONLYNUM
	HeapSort<long long int> hs3(LLds);
	CTimer::calc([&](){
		hs3.Sort();
	},"\t(ONLYNUM) spents %f second(s).");
	if (checkSorted(hs3.arr)) cout << "\t|Sorted - (O)" << endl;
	else cout << "\t|Sorted - (X)" << endl;
#endif


	cout << "(Recursive)MergeSort:" << endl;
#ifdef FULLDATA
	MergeSort<DataSet> ms1(csvDataSet.dataSet);
	CTimer::calc([&](){
		ms1.Sort();
	},"\t(FULLDATA) spents %f second(s).");
	if (checkSorted(ms1.arr)) cout << "\t|Sorted - (O)" << endl;
	else cout << "\t|Sorted - (X)" << endl;
#endif
#ifdef PTRDATA	
	MergeSort<SortData<DataSet>> ms2(ptrDataSet);
	CTimer::calc([&](){
		ms2.Sort();
	},"\t(PTRDATA) spents %f second(s).");
	if (checkSorted(ms2.arr)) cout << "\t|Sorted - (O)" << endl;
	else cout << "\t|Sorted - (X)" << endl;
#endif
#ifdef ONLYNUM
	MergeSort<long long int> ms3(LLds);
	CTimer::calc([&](){
		ms3.Sort();
	},"\t(ONLYNUM) spents %f second(s).");
	if (checkSorted(ms3.arr)) cout << "\t|Sorted - (O)" << endl;
	else cout << "\t|Sorted - (X)" << endl;
#endif


	cout << "(Iterative)MergeSort:" << endl;
#ifdef FULLDATA
	MergeSort<DataSet> msi1(csvDataSet.dataSet);
	CTimer::calc([&](){
		msi1.IterativeSort();
	},"\t(FULLDATA) spents %f second(s).");
	if (checkSorted(msi1.arr)) cout << "\t|Sorted - (O)" << endl;
	else cout << "\t|Sorted - (X)" << endl;
#endif
#ifdef PTRDATA	
	MergeSort<SortData<DataSet>> msi2(ptrDataSet);
	CTimer::calc([&](){
		msi2.IterativeSort();
	},"\t(PTRDATA) spents %f second(s).");
	if (checkSorted(msi2.arr)) cout << "\t|Sorted - (O)" << endl;
	else cout << "\t|Sorted - (X)" << endl;
#endif
#ifdef ONLYNUM
	MergeSort<long long int> msi3(LLds);
	CTimer::calc([&](){
		msi3.IterativeSort();
	},"\t(ONLYNUM) spents %f second(s).");
	if (checkSorted(msi3.arr)) cout << "\t|Sorted - (O)" << endl;
	else cout << "\t|Sorted - (X)" << endl;
#endif
	
	cout << "QuickSort:" << endl;
#ifdef FULLDATA
	QuickSort<DataSet> qs1(csvDataSet.dataSet);
	CTimer::calc([&](){
		qs1.Sort();
	},"\t(FULLDATA) spents %f second(s).");
	if (checkSorted(qs1.arr)) cout << "\t|Sorted - (O)" << endl;
	else cout << "\t|Sorted - (X)" << endl;
#endif
#ifdef PTRDATA	
	QuickSort<SortData<DataSet>> qs2(ptrDataSet);
	CTimer::calc([&](){
		qs2.Sort();
	},"\t(PTRDATA) spents %f second(s).");
	if (checkSorted(qs2.arr)) cout << "\t|Sorted - (O)" << endl;
	else cout << "\t|Sorted - (X)" << endl;
#endif
#ifdef ONLYNUM
	QuickSort<long long int> qs3(LLds);
	CTimer::calc([&](){
		qs3.Sort();
	},"\t(ONLYNUM) spents %f second(s).");
	if (checkSorted(qs3.arr)) cout << "\t|Sorted - (O)" << endl;
	else cout << "\t|Sorted - (X)" << endl;
#endif


	cout << "IntroSort:" << endl;
#ifdef FULLDATA
	IntroSort<DataSet> its1(csvDataSet.dataSet);
	CTimer::calc([&](){
		its1.Sort();
	},"\t(FULLDATA) spents %f second(s).");
	if (checkSorted(its1.arr)) cout << "\t|Sorted - (O)" << endl;
	else cout << "\t|Sorted - (X)" << endl;
#endif
#ifdef PTRDATA	
	IntroSort<SortData<DataSet>> its2(ptrDataSet);
	CTimer::calc([&](){
		its2.Sort();
	},"\t(PTRDATA) spents %f second(s).");
	if (checkSorted(its2.arr)) cout << "\t|Sorted - (O)" << endl;
	else cout << "\t|Sorted - (X)" << endl;
#endif
#ifdef ONLYNUM
	IntroSort<long long int> its3(LLds);
	CTimer::calc([&](){
		its3.Sort();
	},"\t(ONLYNUM) spents %f second(s).");
	if (checkSorted(its3.arr)) cout << "\t|Sorted - (O)" << endl;
	else cout << "\t|Sorted - (X)" << endl;
#endif
	
	
	cout << "InsertionSort:" << endl;
#ifdef FULLDATA
	InsertionSort<DataSet> is1(csvDataSet.dataSet);
	CTimer::calc([&](){
		is1.Sort();
	},"\t(FULLDATA) spents %f second(s).");
	if (checkSorted(is1.arr)) cout << "\t|Sorted - (O)" << endl;
	else cout << "\t|Sorted - (X)" << endl;
#endif
#ifdef PTRDATA	
	InsertionSort<SortData<DataSet>> is2(ptrDataSet);
	CTimer::calc([&](){
		is2.Sort();
	},"\t(PTRDATA) spents %f second(s).");
	if (checkSorted(is2.arr)) cout << "\t|Sorted - (O)" << endl;
	else cout << "\t|Sorted - (X)" << endl;
#endif
#ifdef ONLYNUM
	InsertionSort<long long int> is3(LLds);
	CTimer::calc([&](){
		is3.Sort();
	},"\t(ONLYNUM) spents %f second(s).");
	if (checkSorted(is3.arr)) cout << "\t|Sorted - (O)" << endl;
	else cout << "\t|Sorted - (X)" << endl;
#endif
	
	
}



int main(){
	CTimer::init();
	solve("rooftop-drinking-water-tank-inspection-results.csv",1);
	cout << endl;cout << endl;
	solve("metadata.csv",0);
	cout << endl;cout << endl;
	solve("1000000 Sales Records.csv",4);
	cout << endl << endl;
	return 0;	
}
