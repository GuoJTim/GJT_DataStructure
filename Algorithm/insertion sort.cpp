#include <bits/stdc++.h>
using namespace std;


void insertion_sort(vector<int> &A){
	for (int j = 1 ; j < A.size();j++){
		int key = A[j];
		int i = j - 1;
		while(i >= 0 && A[i] > key){
			A[i+1] = A[i];
			i = i - 1;
		}
		A[i+1] = key;
	}
}

int main(){
	vector<int> data = {6,7,4,2,1,3,6,4,5};
	insertion_sort(data);
	for(int i : data) cout << i << " ";
}

/**
#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
class timer{
public:
static LARGE_INTEGER startTime, endTime, fre;
static double time;
static void start_timer() {
QueryPerformanceCounter(&startTime);
}
static void stop_timer() {
QueryPerformanceCounter(&endTime);
time = ((double)endTime.QuadPart - (double)startTime.QuadPart) /
fre.QuadPart;
}
static string getFormat() {
char tmp[100];
sprintf(tmp, "this action spends about %f second(s).",((float)time)/
CLOCKS_PER_SEC);// string format
string timeformat(tmp);
return timeformat;
}
};
LARGE_INTEGER timer::startTime;
LARGE_INTEGER timer::endTime;
LARGE_INTEGER timer::fre;
double timer::time = 0;


//https://hackmd.io/@GJT/algor_p1
class smallDataSet{
	public:
		string confirmation_num;
		unsigned long long bbl;
		string lab_name;
		string nta;
		smallDataSet(string confirmation_num,unsigned long long bbl,string lab_name,string nta){
			this->confirmation_num = confirmation_num;
			this->bbl = bbl;
			this->lab_name = lab_name;
			this->nta = nta;
		}
		bool operator>(smallDataSet &a){
			return this->bbl > a.bbl;
		}
		bool operator<(smallDataSet &a){
			return this->bbl < a.bbl;
		}
};
template <class T>
void insertion_sort(vector<T> &A){
	for (int j = 1 ; j < A.size();j++){
		T key = A[j];
		int i = j - 1;
		while(i >= 0 && A[i] > key){
			A[i+1] = A[i];
			i = i - 1;
		}
		A[i+1] = key;
	}
}
unsigned long long int conv(string s){
	unsigned long long int u = 0;
	for(int i = 0 ; i < s.size();i++){
		u = u * 10 + s[i]-'0';
	}
	return u;
}

int main(){
	QueryPerformanceFrequency(&timer::fre);//aicl?A frequency
	ifstream inFile("1000000 Sales Records.csv",ifstream::in);
	string line, field;
	vector<vector<string>> array;
	vector<string> v;
	vector<smallDataSet> myData; 
	bool skipName = true;
	while(getline(inFile,line)){
		v.clear();
		stringstream str(line);
		while(getline(str,field,',')){
			v.push_back(field);
		}
		if (skipName){
			skipName = false;
			continue;
		}
		myData.push_back(smallDataSet(v[0],conv(v[4]),v[2],v[3]));
		array.push_back(v);
	}
	cout << array.size() << endl;
	timer::start_timer();
	insertion_sort<smallDataSet>(myData);
	timer::stop_timer();
	cout << timer::getFormat() << endl;
}


**/
