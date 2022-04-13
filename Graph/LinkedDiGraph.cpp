#include "LinkedDiGraph.h"


LinkedDiGraph::LinkedDiGraph(int nodes) : Graph(nodes){
	adjLists = new Chain<int>[nodes];
	
}

// find 
int LinkedDiGraph::IndexOf(Chain<int> &chain,const int obj){
	int cnt = 0;
	for(Chain<int>::ChainIterator it = chain.begin() ; it != chain.end();it++,cnt++){
		if (*it == obj) return cnt;
	}
	return -1;
}

int LinkedDiGraph::Degree(int u) const {
	return adjLists[u].Length();
}

bool LinkedDiGraph::ExistsEdge(int u,int v){
	int num = v;
	return IndexOf(adjLists[u],v) != -1;
}
void LinkedDiGraph::InsertEdge(int u,int v){
	e++;
	adjLists[u].InsertBack(new ChainNode<int>(v));
}
void LinkedDiGraph::InsertEdge(int u,int v,double w){
	InsertEdge(u,v);
}

void LinkedDiGraph::DeleteVertex(int v){
	adjLists[v].~Chain(); 
	adjLists[v] = Chain<int>();
	for (int i = 0 ; i < nodes ; i++){
		if(i == v) continue;
		int removeIndex = IndexOf(adjLists[i],v);
		if (removeIndex != -1){
			adjLists[i].Delete(removeIndex);
			e--;
		}
	}
}
std::vector<int> LinkedDiGraph::adjNodes(int u){
	std::vector<int> vec;
	for(Chain<int>::ChainIterator it = adjLists[u].begin() ; it != adjLists[u].end();it++){
		vec.push_back(*it);
	}
	return vec;
}

void LinkedDiGraph::DeleteEdge(int u,int v){
	int removeIndex = IndexOf(adjLists[u],v);
	if (removeIndex != -1) {
		adjLists[u].Delete(removeIndex);
		e--;
	}
}
#include <iostream>
using namespace std;
LinkedDiGraph::~LinkedDiGraph(){
	for(int i = 0 ; i < nodes;i++){
		adjLists[i].~Chain();
	}
	delete [] adjLists;
}
		
