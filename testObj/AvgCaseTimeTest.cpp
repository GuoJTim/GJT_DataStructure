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


int runs = 100;

void AVGMergeSort(CSVDataSet &csvDataSet ,vector<SortData<DataSet>> &ptrDataSet,vector<long long int> &LLds){
	cout << "(Recursive)MergeSort:" << endl;
	if(FULLDATA){
		double ctime = 0;
		for(int i = 0 ; i < runs;i++){
			RandomShuffle::arr_shuffle(csvDataSet.dataSet);	
			MergeSort<DataSet> ms1(csvDataSet.dataSet);
			ctime += CTimer::calc([&](){
				ms1.Sort();
			},"");
			if (!checkSorted(ms1.arr)) throw "sort error";
		}
		printf("\t(FULLDATA) \t%d runs avg-case spents %f second(s).\n",runs,ctime/runs);
	}
	if(PTRDATA){
		double ctime = 0;
		for(int i = 0 ; i < runs;i++){
			RandomShuffle::arr_shuffle(ptrDataSet);	
			MergeSort<SortData<DataSet>> ms2(ptrDataSet);
			ctime += CTimer::calc([&](){
				ms2.Sort();
			},"");
			if (!checkSorted(ms2.arr)) throw "sort error";
		}
		printf("\t(PTRDATA) \t%d runs avg-case spents %f second(s).\n",runs,ctime/runs);
	}
	if(ONLYNUM){
		double ctime = 0;
		for(int i = 0 ; i < runs;i++){
			RandomShuffle::arr_shuffle(LLds);	
			MergeSort<long long int> ms3(LLds);
			ctime += CTimer::calc([&](){
				ms3.Sort();
			},"");//\t(FULLDATA) spents %f second(s).
			if (!checkSorted(ms3.arr)) throw "sort error";
		}
		printf("\t(ONLYNUM) \t%d runs avg-case spents %f second(s).\n",runs,ctime/runs);
	}	
	cout << "(Iterative)MergeSort:" << endl;
	if(FULLDATA){
		double ctime = 0;
		for(int i = 0 ; i < runs;i++){
			RandomShuffle::arr_shuffle(csvDataSet.dataSet);	
			MergeSort<DataSet> msi1(csvDataSet.dataSet);
			ctime += CTimer::calc([&](){
				msi1.IterativeSort();
			},"");//\t(FULLDATA) spents %f second(s).
			if (!checkSorted(msi1.arr)) throw "sort error";
		}
		printf("\t(FULLDATA) \t%d runs avg-case spents %f second(s).\n",runs,ctime/runs);
	}
	if(PTRDATA){
		double ctime = 0;
		for(int i = 0 ; i < runs;i++){
			RandomShuffle::arr_shuffle(ptrDataSet);	
			MergeSort<SortData<DataSet>> msi2(ptrDataSet);
			ctime += CTimer::calc([&](){
				msi2.IterativeSort();
			},"");//\t(FULLDATA) spents %f second(s).
			if (!checkSorted(msi2.arr)) throw "sort error";
		}
		printf("\t(PTRDATA) \t%d runs avg-case spents %f second(s).\n",runs,ctime/runs);
	}
	if(ONLYNUM){
		double ctime = 0;
		for(int i = 0 ; i < runs;i++){
			RandomShuffle::arr_shuffle(LLds);	
			MergeSort<long long int> msi3(LLds);
			ctime += CTimer::calc([&](){
				msi3.IterativeSort();
			},"");//\t(FULLDATA) spents %f second(s).
			if (!checkSorted(msi3.arr)) throw "sort error";
		}
		printf("\t(ONLYNUM) \t%d runs avg-case spents %f second(s).\n",runs,ctime/runs);
	}	
}

void AVGHeapSort(CSVDataSet &csvDataSet ,vector<SortData<DataSet>> &ptrDataSet,vector<long long int> &LLds){
	cout << "HeapSort:" << endl;
	if(FULLDATA){
		double ctime = 0;
		for(int i = 0 ; i < runs;i++){
			RandomShuffle::arr_shuffle(csvDataSet.dataSet);	
			HeapSort<DataSet> hs1(csvDataSet.dataSet);
			ctime += CTimer::calc([&](){
				hs1.Sort();
			},"");//\t(FULLDATA) spents %f second(s).
			if (!checkSorted(hs1.arr)) throw "sort error";
		}
		printf("\t(FULLDATA) \t%d runs avg-case spents %f second(s).\n",runs,ctime/runs);
	}
	if(PTRDATA){
		double ctime = 0;
		for(int i = 0 ; i < runs;i++){
			RandomShuffle::arr_shuffle(ptrDataSet);	
			HeapSort<SortData<DataSet>> hs2(ptrDataSet);
			ctime += CTimer::calc([&](){
				hs2.Sort();
			},"");//\t(FULLDATA) spents %f second(s).
			if (!checkSorted(hs2.arr)) throw "sort error";
		}
		printf("\t(PTRDATA) \t%d runs avg-case spents %f second(s).\n",runs,ctime/runs);
		
	}
	if(ONLYNUM){
		double ctime = 0;
		for(int i = 0 ; i < runs;i++){
			RandomShuffle::arr_shuffle(LLds);	
			HeapSort<long long int> hs3(LLds);
			ctime += CTimer::calc([&](){
				hs3.Sort();
			},"");//\t(FULLDATA) spents %f second(s).
			if (!checkSorted(hs3.arr)) throw "sort error";
		}
		printf("\t(ONLYNUM) \t%d runs avg-case spents %f second(s).\n",runs,ctime/runs);
		
	}	
}

void AVGIntroSort(CSVDataSet &csvDataSet ,vector<SortData<DataSet>> &ptrDataSet,vector<long long int> &LLds){
	cout << "IntroSort:" << endl;
	if(FULLDATA){
		double ctime = 0;
		for(int i = 0 ; i < runs;i++){
			RandomShuffle::arr_shuffle(csvDataSet.dataSet);	
			IntroSort<DataSet> its1(csvDataSet.dataSet);
			ctime += CTimer::calc([&](){
				its1.Sort();
			},"");//\t(FULLDATA) spents %f second(s).
			if (!checkSorted(its1.arr)) throw "sort error";
		}
		printf("\t(FULLDATA) \t%d runs avg-case spents %f second(s).\n",runs,ctime/runs);
	}
	if(PTRDATA){
		double ctime = 0;
		for(int i = 0 ; i < runs;i++){
			RandomShuffle::arr_shuffle(ptrDataSet);	
			IntroSort<SortData<DataSet>> its2(ptrDataSet);
			ctime += CTimer::calc([&](){
				its2.Sort();
			},"");//\t(FULLDATA) spents %f second(s).
			if (!checkSorted(its2.arr)) throw "sort error";
		}
		printf("\t(PTRDATA) \t%d runs avg-case spents %f second(s).\n",runs,ctime/runs);
	}
	if(ONLYNUM){
		double ctime = 0;
		for(int i = 0 ; i < runs;i++){
			RandomShuffle::arr_shuffle(LLds);	
			IntroSort<long long int> its3(LLds);
			ctime += CTimer::calc([&](){
				its3.Sort();
			},"");//\t(FULLDATA) spents %f second(s).
			if (!checkSorted(its3.arr)) throw "sort error";
		}
		printf("\t(ONLYNUM) \t%d runs avg-case spents %f second(s).\n",runs,ctime/runs);

	}	
}

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
	
	
	AVGMergeSort(csvDataSet,ptrDataSet,LLds);
	AVGHeapSort(csvDataSet,ptrDataSet,LLds);
	AVGInsertionSort(csvDataSet,ptrDataSet,LLds);
	AVGIntroSort(csvDataSet,ptrDataSet,LLds);
	AVGQuickSort(csvDataSet,ptrDataSet,LLds);
}
