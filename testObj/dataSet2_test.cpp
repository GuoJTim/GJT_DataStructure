#include "../Sorting/everything.h"
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

class DataSet{
	public:
		unsigned long long pubmed_id;
		string pmcid;
		string OAK_MEADOW;
		DataSet(){
			//for heap sort init
		}
		DataSet(vector<string> obj){
			pubmed_id = conv(obj[0]);
			pmcid = obj[1];
			if (obj.size() > 2)	OAK_MEADOW = obj[2];
		}
		bool operator>(const DataSet& a) const{
			return this->pubmed_id > a.pubmed_id;
		}
		bool operator<(const DataSet& a) const{
			return this->pubmed_id < a.pubmed_id;
		}
		bool operator==(const DataSet& a) const{
			return this->pubmed_id == a.pubmed_id;
		}
		
		friend std::ostream& operator<<(std::ostream& ,DataSet&); // for cout
};

ostream& operator<<(ostream& os,DataSet &obj){
	os << obj.pubmed_id;
	return os;
}


int main(){
	CTimer::init();
	ExcelReader<DataSet> rd("metadata.csv");
	
	vector<DataSet> file;
	rd.readAsObjectVector(file);
	
	cout << "data:" << file.size() << endl;
	
	cout << "InsertionSort:";
	InsertionSort<DataSet,greater<DataSet>> is(file);
	
	CTimer::start_timer();
	is.Sort();
	CTimer::stop_timer();
	cout << CTimer::getFormat() << endl;
	
	cout << "QuickSort(pivot right):";
	QuickSort<DataSet> qs(file);
	
	CTimer::start_timer();
	qs.Sort();
	CTimer::stop_timer();
	
	cout << CTimer::getFormat() << endl;
	
	cout << "QuickSort(median of three):";
	QuickSort<DataSet> qs2(file);
	
	CTimer::start_timer();
	qs2.SortWithMedianOfThree();
	CTimer::stop_timer();
	
	cout << CTimer::getFormat() << endl;
	
	cout << "HeapSort:";
	HeapSort<DataSet> hs(file);
	
	CTimer::start_timer();
	hs.Sort();
	CTimer::stop_timer();
	
	//hs.show_list(true);
	cout << CTimer::getFormat() << endl;
	
	
	cout << "MergeSort(recursion):";
	MergeSort<DataSet> ms(file);
	
	CTimer::start_timer();
	ms.Sort();
	CTimer::stop_timer();
	
	//ms.show_list(true);
	cout << CTimer::getFormat() << endl;
	
	
	
}
