#include "../Sorting/everything.h"
#include "../Sorting/SortData.h"
#include "../Utils/CTimer.h"
#include "../Utils/ExcelReader.h"
#include "../Utils/CSVDataSet.cpp"
#include "../Utils/RandomShuffle.h"
bool FULLDATA = true;
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


int runs = 10;


void AVGQuickSort(CSVDataSet &csvDataSet ,vector<SortData<DataSet>> &ptrDataSet,vector<long long int> &LLds){
	cout << "QuickSort:" << endl;
	if(FULLDATA){
		double ctime = 0;
		for(int i = 0 ; i < runs;i++){
			RandomShuffle::arr_shuffle(csvDataSet.dataSet);	
			QuickSort<DataSet> qs1(csvDataSet.dataSet);
			ctime += CTimer::calc([&](){
				qs1.Sort();
			},"");//\t(FULLDATA) spents %f second(s).
			if (!checkSorted(qs1.arr)) throw "sort error";
		}
		printf("\t(FULLDATA) \t%d runs avg-case spents %f second(s).\n",runs,ctime/runs);
	}
	if(PTRDATA){
		double ctime = 0;
		for(int i = 0 ; i < runs;i++){
			RandomShuffle::arr_shuffle(ptrDataSet);	
			QuickSort<SortData<DataSet>> qs2(ptrDataSet);
			ctime += CTimer::calc([&](){
				qs2.Sort();
			},"");//\t(FULLDATA) spents %f second(s).
			if (!checkSorted(qs2.arr)) throw "sort error";
		}
		printf("\t(PTRDATA) \t%d runs avg-case spents %f second(s).\n",runs,ctime/runs);

	}
	if(ONLYNUM){
		double ctime = 0;
		for(int i = 0 ; i < runs;i++){
			RandomShuffle::arr_shuffle(LLds);	
			QuickSort<long long int> qs3(LLds);
			ctime += CTimer::calc([&](){
				qs3.Sort();
			},"");//\t(FULLDATA) spents %f second(s).
			if (!checkSorted(qs3.arr)) throw "sort error";
		}
		printf("\t(ONLYNUM) \t%d runs avg-case spents %f second(s).\n",runs,ctime/runs);

	}
	
	cout << "QuickSort(MedianOfThree):" << endl;
	if(FULLDATA){
		double ctime = 0;
		for(int i = 0 ; i < runs;i++){
			RandomShuffle::arr_shuffle(csvDataSet.dataSet);	
			QuickSort<DataSet> qsm1(csvDataSet.dataSet);
			ctime += CTimer::calc([&](){
				qsm1.SortWithMedianOfThree();
			},"");//\t(FULLDATA) spents %f second(s).
			if (!checkSorted(qsm1.arr)) throw "sort error";
		}
		printf("\t(FULLDATA) \t%d runs avg-case spents %f second(s).\n",runs,ctime/runs);
	}
	if(PTRDATA){
		double ctime = 0;
		for(int i = 0 ; i < runs;i++){
			RandomShuffle::arr_shuffle(ptrDataSet);	
			QuickSort<SortData<DataSet>> qsm2(ptrDataSet);
			ctime += CTimer::calc([&](){
				qsm2.SortWithMedianOfThree();
			},"");//\t(FULLDATA) spents %f second(s).
			if (!checkSorted(qsm2.arr)) throw "sort error";
		}
		printf("\t(PTRDATA) \t%d runs avg-case spents %f second(s).\n",runs,ctime/runs);
	}
	if(ONLYNUM){
		double ctime = 0;
		for(int i = 0 ; i < runs;i++){
			RandomShuffle::arr_shuffle(LLds);	
			QuickSort<long long int> qsm3(LLds);
			ctime += CTimer::calc([&](){
				qsm3.SortWithMedianOfThree();
			},"");//\t(FULLDATA) spents %f second(s).
			if (!checkSorted(qsm3.arr)) throw "sort error";
		}
		printf("\t(ONLYNUM) \t%d runs avg-case spents %f second(s).\n",runs,ctime/runs);
		
		
	}	
}

void AVGInsertionSort(CSVDataSet &csvDataSet ,vector<SortData<DataSet>> &ptrDataSet,vector<long long int> &LLds){
	cout << "InsertionSort:" << endl;
	if(FULLDATA){
		double ctime = 0;
		for(int i = 0 ; i < runs;i++){
			RandomShuffle::arr_shuffle(csvDataSet.dataSet);	
			InsertionSort<DataSet> is1(csvDataSet.dataSet);
			ctime += CTimer::calc([&](){
				is1.Sort();
			},"");//\t(FULLDATA) spents %f second(s).
			if (!checkSorted(is1.arr)) throw "sort error";
		}
		printf("\t(FULLDATA) \t%d runs avg-case spents %f second(s).\n",runs,ctime/runs);
		
		
	}
	if(PTRDATA){
		double ctime = 0;
		for(int i = 0 ; i < runs;i++){
			RandomShuffle::arr_shuffle(ptrDataSet);	
			InsertionSort<SortData<DataSet>> is2(ptrDataSet);
			ctime += CTimer::calc([&](){
				is2.Sort();
			},"");//\t(FULLDATA) spents %f second(s).
			if (!checkSorted(is2.arr)) throw "sort error";
		}
		printf("\t(PTRDATA) \t%d runs avg-case spents %f second(s).\n",runs,ctime/runs);
		
	}
	if(ONLYNUM){
		double ctime = 0;
		for(int i = 0 ; i < runs;i++){
			RandomShuffle::arr_shuffle(LLds);	
			InsertionSort<long long int> is3(LLds);
			ctime += CTimer::calc([&](){
				is3.Sort();
			},"");//\t(FULLDATA) spents %f second(s).
			if (!checkSorted(is3.arr)) throw "sort error";
		}
		printf("\t(ONLYNUM) \t%d runs avg-case spents %f second(s).\n",runs,ctime/runs);
		
	}	
}

void WSTQuickSort(CSVDataSet &csvDataSet ,vector<SortData<DataSet>> &ptrDataSet,vector<long long int> &LLds){
	cout << "QuickSort:" << endl;
	if(FULLDATA){
		QuickSort<DataSet> qs1(csvDataSet.dataSet);
		CTimer::calc([&](){
			qs1.Sort();
		},"\t(FULLDATA) spents %f second(s).");
		if (checkSorted(qs1.arr)) cout << "\t|Sorted - (O)" << endl;
		else cout << "\t|Sorted - (X)" << endl;
	}
	if(PTRDATA){
		QuickSort<SortData<DataSet>> qs2(ptrDataSet);
		CTimer::calc([&](){
			qs2.Sort();
		},"\t(PTRDATA) spents %f second(s).");
		if (checkSorted(qs2.arr)) cout << "\t|Sorted - (O)" << endl;
		else cout << "\t|Sorted - (X)" << endl;
	}
	if(ONLYNUM){
		QuickSort<long long int> qs3(LLds);
		CTimer::calc([&](){
			qs3.Sort();
		},"\t(ONLYNUM) spents %f second(s).");
		if (checkSorted(qs3.arr)) cout << "\t|Sorted - (O)" << endl;
		else cout << "\t|Sorted - (X)" << endl;
	}
	
	cout << "QuickSort(MedianOfThree):" << endl;
	if(FULLDATA){
		QuickSort<DataSet> qsm1(csvDataSet.dataSet);
		CTimer::calc([&](){
			qsm1.SortWithMedianOfThree();
		},"\t(FULLDATA) spents %f second(s).");
		if (checkSorted(qsm1.arr)) cout << "\t|Sorted - (O)" << endl;
		else cout << "\t|Sorted - (X)" << endl;
	}
	if(PTRDATA){
		QuickSort<SortData<DataSet>> qsm2(ptrDataSet);
		CTimer::calc([&](){
			qsm2.SortWithMedianOfThree();
		},"\t(PTRDATA) spents %f second(s).");
		if (checkSorted(qsm2.arr)) cout << "\t|Sorted - (O)" << endl;
		else cout << "\t|Sorted - (X)" << endl;
	}
	if(ONLYNUM){
		QuickSort<long long int> qsm3(LLds);
		CTimer::calc([&](){
			qsm3.SortWithMedianOfThree();
		},"\t(ONLYNUM) spents %f second(s).");
		if (checkSorted(qsm3.arr)) cout << "\t|Sorted - (O)" << endl;
		else cout << "\t|Sorted - (X)" << endl;
	}	
}

void WSTInsertionSort(CSVDataSet &csvDataSet ,vector<SortData<DataSet>> &ptrDataSet,vector<long long int> &LLds){
	cout << "InsertionSort:" << endl;
	if(FULLDATA){
		InsertionSort<DataSet> is1(csvDataSet.dataSet);
		CTimer::calc([&](){
			is1.Sort();
		},"\t(FULLDATA) spents %f second(s).");
		if (checkSorted(is1.arr)) cout << "\t|Sorted - (O)" << endl;
		else cout << "\t|Sorted - (X)" << endl;
	}
	if(PTRDATA){
		InsertionSort<SortData<DataSet>> is2(ptrDataSet);
		CTimer::calc([&](){
			is2.Sort();
		},"\t(PTRDATA) spents %f second(s).");
		if (checkSorted(is2.arr)) cout << "\t|Sorted - (O)" << endl;
		else cout << "\t|Sorted - (X)" << endl;
	}
	if(ONLYNUM){
		InsertionSort<long long int> is3(LLds);
		CTimer::calc([&](){
			is3.Sort();
		},"\t(ONLYNUM) spents %f second(s).");
		if (checkSorted(is3.arr)) cout << "\t|Sorted - (O)" << endl;
		else cout << "\t|Sorted - (X)" << endl;
	}	
}




int main(){
	string fileName = "metadata.csv";
	int sortHeader = 0;
	ExcelReader rawFile(fileName);
	CSVDataSet csvDataSet;
	vector<SortData<DataSet>> ptrDataSet;
	
	vector<long long int> LLds;
	
	cout << "Loading DataSets...(" << fileName << ")" << endl;
	CTimer::calc([&](){
		rawFile.readAsCSVDataSet(csvDataSet,sortHeader);
		if(PTRDATA){                                    
			ptrDataSet = SortData<DataSet>::createData(csvDataSet.dataSet);
		}                                         
		if(ONLYNUM){
			LLds = toLLvec(csvDataSet.dataSet);
		}                                   
	},"Loaded data ,spents %f second(s).\n");
	
	
	AVGInsertionSort(csvDataSet,ptrDataSet,LLds);
	AVGQuickSort(csvDataSet,ptrDataSet,LLds);
	sort(csvDataSet.dataSet.rbegin(),csvDataSet.dataSet.rend()); // 反向排序
	sort(ptrDataSet.rbegin(),ptrDataSet.rend()); // 反向排序
	sort(LLds.rbegin(),LLds.rend()); // 反向排序
	WSTInsertionSort(csvDataSet,ptrDataSet,LLds);
	
	for (int i = 0 ; i < csvDataSet.dataSet.size();i++){
		if (FULLDATA)csvDataSet.dataSet[i].val = 1;
		if (PTRDATA)ptrDataSet[i].pointer->val = 1;
		if (ONLYNUM)LLds[i] = 1;
	}
	WSTQuickSort(csvDataSet,ptrDataSet,LLds);
	
}
