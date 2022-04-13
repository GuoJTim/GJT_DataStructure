#include <vector>
#ifndef DSU_H
#define DSU_H

class DSU{
	private:
		std::vector<int> parent;
		std::vector<int> size;
		std::vector<std::vector<int>> family; 
	public:
		DSU(int nodes);
		DSU();
		void resize(int newSize);
		int find(int index);
		void Union(int a,int b);
		std::vector<int> getFamily(int index);
	
};
#include "DSU.cpp"
#endif


