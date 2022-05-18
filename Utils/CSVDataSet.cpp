#ifndef CSVDataSet_H
#define CSVDataSet_H // sorting for big data
#include <vector>
#include <string>
#include <ostream>
#include <iostream>
#include <iomanip>

//each line data
class DataSet{
	public:
		std::vector<std::string> data;
		long long int val;
		
		DataSet(){
			//init
			
		}
		DataSet(std::vector<std::string> obj){
			data = obj;
		}
		DataSet(std::vector<std::string> obj,int index){ // index -> which should be sort
			data = obj;
			try{
				val = stoll(obj[index]);
			}catch(...){
				std::cout << "[error] cannot cast to int: " << obj[index] << std::endl;
			}
		}
		bool operator>(const DataSet& a) const{
			return val > a.val;
		}
		bool operator<(const DataSet& a) const{
			return val < a.val;
		}
		bool operator==(const DataSet& a) const{
			return val == a.val;
		}
		
		std::string& operator[](int index){
			if (index >= data.size()){
				std::cout << "Array index out of bound, exiting";
        		exit(0);
			}
			return data[index];
		}
		
		
		friend std::ostream& operator<<(std::ostream& ,DataSet&); // for cout
};


// entire data include header
class CSVDataSet{
	public:
		std::vector<int> gap;
		std::vector<std::string> header;
		std::vector<DataSet> dataSet;
		CSVDataSet(std::vector<std::string> header){
			this->header = header;
			for (std::string &s:header){
				gap.push_back(s.size()+2);
			}
		}
		CSVDataSet(){
			
		}
		void clearData(){
			dataSet.clear();
		}
		void setHeader(std::vector<std::string> header){
			this->header = header;
		}
		
		
		
		DataSet& operator[](int index){
			if (index >= dataSet.size()){
				std::cout << "Array index out of bound, exiting";
        		exit(0);
			}
			return dataSet[index];
		}
		friend std::ostream& operator<<(std::ostream& ,CSVDataSet&); // for cout
		
};


std::ostream& operator<<(std::ostream& os,DataSet &obj){
	for(std::string& s : obj.data){
		os << std::setw(20) << s ;
	}
	return os;
}


std::ostream& operator<<(std::ostream& os,CSVDataSet &obj){
	int i = 0;
	for (std::string &header: obj.header){
		os << std::setw(20) <<  header;
	}
	os << std::endl;
	for(DataSet& ds : obj.dataSet){
		os << ds << std::endl;
	}
	return os;
}

#endif