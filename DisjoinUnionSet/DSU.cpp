#include "DSU.h"
#include <algorithm>
DSU::DSU(int nodes){
	resize(nodes);
}
DSU::DSU(){
	
}
void DSU::resize(int newSize){
	parent.resize(newSize);
	family.resize(newSize);
	for(int i = 0; i < newSize ; i++){
		parent[i] = i;
		family[i].push_back(i);
	}
    size.resize(newSize,1);
}

int DSU::find(int index){
    if (parent[index] == index) return index;
    return parent[index] = find(parent[index]);
}
void DSU::Union(int a,int b){
    int fa = find(a),fb = find(b);
	if (size[fb] > size[fa]) std::swap(fa,fb);
	size[fa] += size[fb];
	parent[fb] = fa;
    family[fa].insert(family[fa].end(),family[fb].begin(),family[fb].end());
}
std::vector<int> DSU::getFamily(int index){
	return family[index];
}
