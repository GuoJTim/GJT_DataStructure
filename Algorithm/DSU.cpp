#include <bits/stdc++.h>
using namespace std;

int find(int index){
	if (parent[index] == index) return index;
	return parent[index] = find(parent[index]);
}

void Union(int a,int b){
	int fa = find(a),fb = find(b);
	if (sizez[fb] > size[fa]) swap(fa,fb);
	size[fa] += size[fb];
	parent[fb] = fa;
}

int main(){
	
}
