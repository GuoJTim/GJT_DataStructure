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
	
	cout << "(Recursive)MergeSort:" << endl;
	if(FULLDATA){
		MergeSort<DataSet> ms1(csvDataSet.dataSet);
		CTimer::calc([&](){
			ms1.Sort();
		},"\t(FULLDATA) spents %f second(s).");
		if (checkSorted(ms1.arr)) cout << "\t|Sorted - (O)" << endl;
		else cout << "\t|Sorted - (X)" << endl;
	}
	if(PTRDATA){
		MergeSort<SortData<DataSet>> ms2(ptrDataSet);
		CTimer::calc([&](){
			ms2.Sort();
		},"\t(PTRDATA) spents %f second(s).");
		if (checkSorted(ms2.arr)) cout << "\t|Sorted - (O)" << endl;
		else cout << "\t|Sorted - (X)" << endl;
	}
	if(ONLYNUM){
		MergeSort<long long int> ms3(LLds);
		CTimer::calc([&](){
			ms3.Sort();
		},"\t(ONLYNUM) spents %f second(s).");
		if (checkSorted(ms3.arr)) cout << "\t|Sorted - (O)" << endl;
		else cout << "\t|Sorted - (X)" << endl;
	}	
	
	cout << "(Iterative)MergeSort:" << endl;
	if(FULLDATA){
		MergeSort<DataSet> msi1(csvDataSet.dataSet);
		CTimer::calc([&](){
			msi1.IterativeSort();
		},"\t(FULLDATA) spents %f second(s).");
		if (checkSorted(msi1.arr)) cout << "\t|Sorted - (O)" << endl;
		else cout << "\t|Sorted - (X)" << endl;
	}
	if(PTRDATA){
		MergeSort<SortData<DataSet>> msi2(ptrDataSet);
		CTimer::calc([&](){
			msi2.IterativeSort();
		},"\t(PTRDATA) spents %f second(s).");
		if (checkSorted(msi2.arr)) cout << "\t|Sorted - (O)" << endl;
		else cout << "\t|Sorted - (X)" << endl;
	}
	if(ONLYNUM){
		MergeSort<long long int> msi3(LLds);
		CTimer::calc([&](){
			msi3.IterativeSort();
		},"\t(ONLYNUM) spents %f second(s).");
		if (checkSorted(msi3.arr)) cout << "\t|Sorted - (O)" << endl;
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