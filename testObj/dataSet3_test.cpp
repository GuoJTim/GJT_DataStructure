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
		string Region;
		string Item_Type;
		string Order_Prior;
		string Order_Date;
		unsigned long long Orider_ID;
		DataSet(){
			//for heap sort init
		}
		DataSet(vector<string> obj){
			Region = obj[0];
			Item_Type = obj[1];
			Order_Prior = obj[2];
			Order_Date = obj[3];
			Orider_ID = conv(obj[4]);
		}
		bool operator>(const DataSet& a) const{
			return this->Orider_ID > a.Orider_ID;
		}
		bool operator<(const DataSet& a) const{
			return this->Orider_ID < a.Orider_ID;
		}
		bool operator==(const DataSet& a) const{
			return this->Orider_ID == a.Orider_ID;
		}
		
		friend std::ostream& operator<<(std::ostream& ,DataSet&); // for cout
};

ostream& operator<<(ostream& os,DataSet &obj){
	os << obj.Orider_ID;
	return os;
}


int main(){
	CTimer::init();
	ExcelReader<DataSet> rd("1000000 Sales Records.csv");
	
	vector<DataSet> file;
	rd.readAsObjectVector(file);
	
	cout << "data:" << file.size() << endl;
	/*
	cout << "InsertionSort:";
	InsertionSort<DataSet,greater<DataSet>> is(file);
	
	CTimer::start_timer();
	is.Sort();
	CTimer::stop_timer();
	cout << CTimer::getFormat() << endl;*/ 
	
	cout << "MergeSort(recursion):";
	MergeSort<DataSet> ms(file);
	
	CTimer::start_timer();
	ms.Sort();
	CTimer::stop_timer();
	
	//ms.show_list(true);
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
	
	
	
	
	
	
}
