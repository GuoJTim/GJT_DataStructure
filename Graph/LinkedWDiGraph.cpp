#include "LinkedWDiGraph.h"
#include <vector>
#include <queue>

LinkedWDiGraph::LinkedWDiGraph(int nodes) : Graph(nodes){
	adjLists = new Chain<node>[nodes];
	dist = new int[nodes];
	parent = new int[nodes];
	D = new int**[nodes+1];
	PI = new int**[nodes+1];
	for (int i = 0 ; i < nodes+1;i++){
		D[i] = new int*[nodes];
		PI[i] = new int*[nodes];
		for(int j = 0 ; j < nodes;j++){
			D[i][j] = new int[nodes];
			PI[i][j] = new int[nodes];
		}
	}
}

// find 
int LinkedWDiGraph::IndexOf(Chain<node> &chain,const int obj){
	int cnt = 0;
	for(Chain<node>::ChainIterator it = chain.begin() ; it != chain.end();it++,cnt++){
		if (it->v == obj) return cnt;
	}
	return -1;
}

int LinkedWDiGraph::Degree(int u) const {
	return adjLists[u].Length();
}

bool LinkedWDiGraph::ExistsEdge(int u,int v){
	int num = v;
	return IndexOf(adjLists[u],v) != -1;
}
void LinkedWDiGraph::InsertEdge(int u,int v){
	InsertEdge(u,v,0);
}
void LinkedWDiGraph::InsertEdge(int u,int v,double w){
	adjLists[u].InsertBack(new ChainNode<node>(node({u,v,w})));
}

void LinkedWDiGraph::DeleteVertex(int v){
	adjLists[v].~Chain(); 
	adjLists[v] = Chain<node>();
	n--;
	for (int i = 0 ; i < nodes ; i++){
		if(i == v) continue;
		int removeIndex = IndexOf(adjLists[i],v);
		if (removeIndex != -1){
			e--;
			adjLists[i].Delete(removeIndex);
		}
	}
}
#include <iostream>
using namespace std;

void LinkedWDiGraph::DeleteEdge(int u,int v){
	int removeIndex = IndexOf(adjLists[u],v);
	if (removeIndex != -1){
		 adjLists[u].Delete(removeIndex);
		 e--;
	}
}

std::vector<int> LinkedWDiGraph::adjNodes(int u){
	std::vector<int> vec;
	for(Chain<node>::ChainIterator it = adjLists[u].begin() ; it != adjLists[u].end();it++){
		vec.push_back(it->v);
	}
	return vec;
}





double LinkedWDiGraph::Kruskal(){
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

double LinkedWDiGraph::Prim(int n){
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

double LinkedWDiGraph::Sollin(){
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

//----------- shortest path

void LinkedWDiGraph::relax(int u,int v){
	int find = IndexOf(adjLists[u],v);
	if(dist[v] > dist[u] + adjLists[u].Get(find)->data.w){
		dist[v] = dist[u] + adjLists[u].Get(find)->data.w;
		parent[v] = u;
	}
}
void LinkedWDiGraph::dijkstra(int source){
	initialize_single_source(source);
	DSU S(nodes);
	priority_queue<node,vector<node>,comp> Q;
	Q.push({source,-1,-1});
	while (Q.size()){
		int u = Q.top().u;Q.pop();
		if (S.find(source) != S.find(u) || S.getSize(source) == 1){
			for(int v : adjNodes(u)){
				relax(u,v);
				int find = IndexOf(adjLists[u],v);
				Q.push({v,-1,adjLists[u].Get(find)->data.w});
			}
			
		}
		S.Union(source,u);
	}
	for(int i = 0 ; i < nodes;i++){
		cout << dist[i] << " ";
	}
	cout << endl;
}
bool LinkedWDiGraph::bellman_ford(int source){
	initialize_single_source(source);
	vector<node> edges;
	for(int u = 0 ; u < nodes;u++){
		for(Chain<node>::ChainIterator it = adjLists[u].begin() ; it != adjLists[u].end();it++){
			edges.push_back({it->u,it->v,it->w});
		}
	}
	for (int i = 0 ; i < nodes;i++){
		for (node edge:edges){
			relax(edge.u,edge.v);
		}
	}
	for(node edge:edges){
		int find = IndexOf(adjLists[edge.u],edge.v);
		if (dist[edge.v] > dist[edge.u] + adjLists[edge.u].Get(find)->data.w){
			return false;
		}
	}
	for (int i = 0 ; i < nodes;i++){
		cout << dist[i] << " ";
	}
	cout << endl;
	return true;
}
void LinkedWDiGraph::floyd_warshall(){
	int n = nodes;
	for(int i = 0 ; i < nodes;i++){
		for(int j = 0 ; j < nodes;j++){
			if (i == j) D[0][i][j] = 0;
			else D[0][i][j] = INT_MAX/2;
		}
		for(Chain<node>::ChainIterator it = adjLists[i].begin() ; it != adjLists[i].end();it++){
			D[0][i][it->v] = it->w;
		}
		cout << endl;
	}
	for(int i = 0 ; i < nodes;i++){
		for(int j = 0 ; j < nodes;j++){
			cout << D[0][i][j] << " ";
		}
	}
	
	
	for(int k = 1 ; k <= nodes;k++){
		for(int i = 0 ; i < nodes;i++){
			for(int j = 0 ; j < nodes;j++){
				
				D[k][i][j] = min(D[k-1][i][j], D[k-1][i][k-1] + D[k-1][k-1][j]);
				cout << D[k][i][j] << " ";
			}
			cout << endl;
		}
		cout << "----" << endl;
	}
	
	
	
	
	
}

void LinkedWDiGraph::initialize_single_source(int source){
	for (int i = 0 ; i < nodes;i++){
		dist[i] = INT_MAX/2;
		parent[i] = -1;
	}
	dist[source] = 0;
}



LinkedWDiGraph::~LinkedWDiGraph(){
	for(int i = 0 ; i < nodes;i++){
		adjLists[i].~Chain();
	}
	delete [] adjLists;
	for(int i = 0 ; i < nodes+1;i++){
		for(int j = 0 ; j < nodes;j++){
			delete[] D[i][j];
			delete[] PI[i][j];
		}
		delete[] D[i];
		delete[] PI[i];
	}
	delete[] D;
	delete[] PI;
	delete[] dist;
	delete[] parent;
	cout << "deleted" << endl;
}
		
