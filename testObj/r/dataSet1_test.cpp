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
		string confirmation_num;
		unsigned long long bbl;
		string lab_name;
		string nta;
		DataSet(){
			//for heap sort init
		}
		DataSet(vector<string> obj){
			confirmation_num = obj[0];
			bbl = conv(obj[1]);
			lab_name = obj[2];
			nta = obj[3];
		}
		bool operator>(const DataSet& a) const{
			return this->bbl > a.bbl;
		}
		bool operator<(const DataSet& a) const{
			return this->bbl < a.bbl;
		}
		bool operator==(const DataSet& a) const{
			return this->bbl == a.bbl;
		}
		
		friend std::ostream& operator<<(std::ostream& ,DataSet&); // for cout
};

ostream& operator<<(ostream& os,DataSet &obj){
	os << obj.confirmation_num << " " << obj.bbl << " " << obj.lab_name << " " << obj.nta;
	return os;
}


int main(){
	CTimer::init();
	ExcelReader<DataSet> rd("rooftop-drinking-water-tank-inspection-results.csv");
	
	
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
