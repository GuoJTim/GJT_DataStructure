#include "../Sorting/everything.h"
#include "../Sorting/SortData.h"
#include "../Utils/CTimer.h"
#include "../Utils/ExcelReader.h"
#include "../Utils/CSVDataSet.cpp"
#include "../Utils/RandomShuffle.h"
bool FULLDATA = false;
bool PTRDATA = false;
bool ONLYNUM = false;

#include <iostream>
#include <ostream>
using namespace std;

template <typename T,typename U = less<T>>
bool checkSorted(vector<T>& data) {
    for (size_t i = 1; i < data.size(); i++) {
        if (U()(data[i],data[i - 1])) {
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
	
	vector<long long int> LLds;
	
	cout << "Loading DataSets...(" << fileName << ")" << endl;
	CTimer::calc([&](){
		rawFile.readAsCSVDataSet(csvDataSet,sortHeader);
		RandomShuffle::arr_shuffle(csvDataSet.dataSet);
		if(PTRDATA){
			ptrDataSet = SortData<DataSet>::createData(csvDataSet.dataSet);
			RandomShuffle::arr_shuffle(ptrDataSet);	
		}
		if(ONLYNUM){
			LLds = toLLvec(csvDataSet.dataSet);
			RandomShuffle::arr_shuffle(LLds);
		}
	},"Loaded data ,spents %f second(s).\n");
	
	cout << "QuickSort:" << endl;
	if(FULLDATA){
		QuickSort<DataSet> qs1;
		CTimer::calc([&](){
			qs1.Sort(csvDataSet.dataSet);
		},"\t(FULLDATA) spents %f second(s).");
		if (checkSorted(csvDataSet.dataSet)) cout << "\t|Sorted - (O)" << endl;
		else cout << "\t|Sorted - (X)" << endl;
	}
	if(PTRDATA){
		QuickSort<SortData<DataSet>> qs2;
		CTimer::calc([&](){
			qs2.Sort(ptrDataSet);
		},"\t(PTRDATA) spents %f second(s).");
		if (checkSorted(ptrDataSet)) cout << "\t|Sorted - (O)" << endl;
		else cout << "\t|Sorted - (X)" << endl;
	}
	if(ONLYNUM){
		QuickSort<long long int> qs3;
		CTimer::calc([&](){
			qs3.Sort(LLds);
		},"\t(ONLYNUM) spents %f second(s).");
		if (checkSorted(LLds)) cout << "\t|Sorted - (O)" << endl;
		else cout << "\t|Sorted - (X)" << endl;
	}
	return;
	cout << "QuickSort(MedianOfThree):" << endl;
	if(FULLDATA){
		QuickSort<DataSet> qsm1;
		CTimer::calc([&](){
			qsm1.SortWithMedianOfThree(csvDataSet.dataSet);
		},"\t(FULLDATA) spents %f second(s).");
		if (checkSorted(csvDataSet.dataSet)) cout << "\t|Sorted - (O)" << endl;
		else cout << "\t|Sorted - (X)" << endl;
	}
	if(PTRDATA){
		QuickSort<SortData<DataSet>> qsm2;
		CTimer::calc([&](){
			qsm2.SortWithMedianOfThree(ptrDataSet);
		},"\t(PTRDATA) spents %f second(s).");
		if (checkSorted(ptrDataSet)) cout << "\t|Sorted - (O)" << endl;
		else cout << "\t|Sorted - (X)" << endl;
	}
	if(ONLYNUM){
		QuickSort<long long int> qsm3;
		CTimer::calc([&](){
			qsm3.SortWithMedianOfThree(LLds);
		},"\t(ONLYNUM) spents %f second(s).");
		if (checkSorted(LLds)) cout << "\t|Sorted - (O)" << endl;
		else cout << "\t|Sorted - (X)" << endl;
	}	
}



int main(int argc, char *argv[]){
	CTimer::init();
	cout << "---------------------------------------------" << endl;
	int type = 1;
	if (argc >= 2) type =atoi(argv[1]); 
	if (argc > 2){
		for (int i = 2 ; i < argc;i++){
			if (strcmp(argv[i],"ONLYNUM") == 0) ONLYNUM = true;
			if (strcmp(argv[i],"FULLDATA") == 0) FULLDATA = true;
			if (strcmp(argv[i],"PTRDATA") == 0) PTRDATA = true;
		}
	}else{
		ONLYNUM = true;
	}
	if (type == 1){
		solve("rooftop-drinking-water-tank-inspection-results.csv",1);
	}
	else if (type == 2){
		solve("metadata.csv",0);
	}
	else{
		solve("1000000 Sales Records.csv",4);
	}
	cout << "---------------------------------------------" << endl;
	
	return 0;	
}