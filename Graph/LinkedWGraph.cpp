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

double LinkedWGraph::Kruskal(){
	dsu.resize(nodes);
	priority_queue<node,vector<node>,comp> queue;
	for(int u = 0 ; u < nodes;u++){
		for(Chain<node>::ChainIterator it = adjLists[u].begin() ; it != adjLists[u].end();it++){
			queue.push({it->u,it->v,it->w});
		}
	}
	
	double weight = 0;
	
	while(queue.size()){
		node k = queue.top();queue.pop();
		if (dsu.find(k.u) != dsu.find(k.v)){
			dsu.Union(k.u,k.v);
			weight += k.w;
		}
	}
	return weight;
}

double LinkedWGraph::Prim(int n){
	dsu.resize(nodes);
	priority_queue<node,vector<node>,comp> queue;
	for(Chain<node>::ChainIterator it = adjLists[n].begin() ; it != adjLists[n].end();it++){
		queue.push({it->u,it->v,it->w});
	}
	double weight = 0;
	while(queue.size()){
		node k = queue.top();queue.pop();
		if (dsu.find(k.u) != dsu.find(k.v)){
			dsu.Union(k.u,k.v);
			weight += k.w;
			for(Chain<node>::ChainIterator it = adjLists[k.v].begin() ; it != adjLists[k.v].end();it++){
				queue.push({it->u,it->v,it->w});
			}
		}
	}
	return weight;
}

double LinkedWGraph::Sollin(){
	dsu.resize(nodes);
	double weight = 0;
	vector<priority_queue<node,vector<node>,comp> > g(nodes);
	for(int i = 0 ; i < nodes; i++){
		for(Chain<node>::ChainIterator it = adjLists[i].begin() ; it != adjLists[i].end();it++){
			g[i].push(*it);
		}
	}
	
	for(int i = 0 ; i < g.size();i++){
        int u = i;
        int v = g[i].top().v;
        int w = g[i].top().w;
		if(dsu.find(u) != dsu.find(v)){
			//union
			cout << "link " << u << "->" << v << " with " << w << endl;
			weight += w;  
			dsu.Union(u,v);
		}
		g[i].pop();	
	}
	
	
	
	bool check[nodes];
	fill(check,check+nodes,false);
	for (int i = 0 ; i < g.size();i++){
		int parent = dsu.find(i);
		if(check[parent]) continue;
		check[parent] = true;
        priority_queue<node,vector<node>,comp> lg;
		for (int u : dsu.getFamily(parent)){
			while(g[u].size()){
				if(dsu.find(g[u].top().v) != dsu.find(g[u].top().u)) lg.push(g[u].top()); // if choose this edge are not cycle then push into queue
				g[u].pop();
				
			}
			
		}
		if(!lg.size()) continue;
		cout << "link " << lg.top().u << "->" << lg.top().v << " with " << lg.top().w << endl;
		dsu.Union(i,lg.top().v);
		weight += lg.top().w;
	}
	return weight;
	
}

LinkedWGraph::~LinkedWGraph(){
	
}
