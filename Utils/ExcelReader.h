#ifndef ExcelReader_H
#define ExcelReader_H
#include "CSVDataSet.cpp"
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

class ExcelReader{
	private:
		ifstream excelFile;
	public:
		ExcelReader(string fileName);
		
		template <class T>
		void readAsObjectVector(vector<T> &outputVector);
		void readAsCSVDataSet(CSVDataSet &outputObj,int index = 0);
	
};
#include "ExcelReader.cpp"
#endif
