#include "ExcelReader.h"

ExcelReader::ExcelReader(string filename){
	excelFile.open(filename,ifstream::in);
}
template <class T>
void ExcelReader::readAsObjectVector(vector<T> &outputObj){
	string line, field;
	vector<vector<string>> array;
	vector<string> v;
	bool skipName = true;
	while(getline(excelFile,line)){
		v.clear();
		stringstream str(line);
		while(getline(str,field,',')){
			v.push_back(field);
		}
		if (skipName){
			skipName = false;
			continue;
		}
		outputObj.push_back(T(v));
		array.push_back(v);
	}
}

void ExcelReader::readAsCSVDataSet(CSVDataSet &outputObj,int index){
	outputObj.clearData();
	string line, field;
	vector<vector<string>> array;
	vector<string> v;
	bool skipName = true;
	while(getline(excelFile,line)){
		v.clear();
		stringstream str(line);
		while(getline(str,field,',')){
			v.push_back(field);
		}
		if (skipName){
			outputObj.setHeader(v);
			skipName = false;
			continue;
		}
		outputObj.dataSet.push_back(DataSet(v,index));
		array.push_back(v);
	}
}

