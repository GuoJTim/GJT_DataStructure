#include "ExcelReader.h"

template <class T>
ExcelReader<T>::ExcelReader(string filename){
	excelFile.open(filename,ifstream::in);
}

template <class T>
void ExcelReader<T>::readAsObjectVector(vector<T> &outputObj){
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

