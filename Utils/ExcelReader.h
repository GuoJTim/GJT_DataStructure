#ifndef ExcelReader_H
#define ExcelReader_H
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

template <class T>
class ExcelReader{
	private:
		ifstream excelFile;
	public:
		ExcelReader(string fileName);
		void readAsObjectVector(vector<T> &outputVector);
	
};
#include "ExcelReader.cpp"
#endif
