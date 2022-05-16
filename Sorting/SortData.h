#ifndef SortData_H
#define SortData_H // sorting for big data
#include <vector>
#include <ostream>


template <class T>
class SortData{
	public:
		T *pointer;
		static std::vector<SortData> createData(std::vector<T> &inputData){
			std::vector<SortData> sd;
			for(T& obj : inputData){
				sd.push_back(SortData(obj));
			}
			return sd;
		}
		SortData(){
			// for init constructor
		}
		SortData(T &data){
			// get the data pointer
			// when sorting using this class
			// swapping pointer instead of swapping data
			pointer = &data;
		}
		bool operator>(const SortData& a) const{
			return *(this->pointer) > *(a.pointer);
		}
		bool operator<(const SortData& a) const{
			return *(this->pointer) < *(a.pointer);
		}
		bool operator<=(const SortData& a) const{
			return *(this->pointer) < *(a.pointer) || *(this->pointer) == *(a.pointer);
		}
		bool operator>=(const SortData& a) const{
			return *(this->pointer) > *(a.pointer) || *(this->pointer) == *(a.pointer);
		}
		bool operator==(const SortData& a) const{
			return *(this->pointer) == *(a.pointer);
		}
		friend std::ostream& operator<<(std::ostream& ,SortData&); // for cout
		
};

#endif