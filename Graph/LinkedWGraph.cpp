#include "LinkedWGraph.h"

LinkedWGraph::LinkedWGraph(int nodes) : LinkedWDiGraph(nodes){
	
}

void LinkedWGraph::InsertEdge(int u,int v){
	InsertEdge(u,v,0);
}
void LinkedWGraph::InsertEdge(int u,int v,double w){
	e+=2;
	adjLists[u].InsertBack(new ChainNode<node>(node({u,v,w})));
	adjLists[v].InsertBack(new ChainNode<node>(node({v,u,w})));
}



void LinkedWGraph::DeleteEdge(int u,int v){
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


LinkedWGraph::~LinkedWGraph(){
	
}
