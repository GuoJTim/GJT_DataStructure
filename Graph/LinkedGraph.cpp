#include "LinkedGraph.h"

LinkedGraph::LinkedGraph(int nodes) : LinkedDiGraph(nodes){
	
}
void LinkedGraph::InsertEdge(int u,int v){
	e+=2;
	adjLists[u].InsertBack(new ChainNode<int>(v));
	adjLists[v].InsertBack(new ChainNode<int>(u));
}
void LinkedGraph::InsertEdge(int u,int v,double w){
	InsertEdge(u,v);
}
void LinkedGraph::DeleteEdge(int u,int v){
	int removeIndex = IndexOf(adjLists[u],v);
	if (removeIndex != -1) {
		adjLists[u].Delete(removeIndex);
		e--;
	}
	
	removeIndex = IndexOf(adjLists[v],u);
	if (removeIndex != -1) {
		adjLists[v].Delete(removeIndex);
		e--;
	}
}

LinkedGraph::~LinkedGraph(){
	
}
