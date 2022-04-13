#include "MatrixWDiGraph.h"
#include <vector>
#include <queue>
MatrixWDiGraph::MatrixWDiGraph(int nodes): Graph(nodes){
	matrix.resize(nodes,std::vector<bool>(nodes,false));
	weight.resize(nodes,std::vector<double>(nodes,0));
}

int MatrixWDiGraph::Degree(int u) const {
	int cnt = 0;
	for(int i = 0 ; i < nodes;i++){
		if (matrix[u][i] || matrix[i][u]) cnt++;// 與他有相關連的邊都計算 
	}
	return cnt;
}
bool MatrixWDiGraph::ExistsEdge(int u,int v){
	return matrix[u][v];
}
void MatrixWDiGraph::InsertEdge(int u,int v){
	InsertEdge(u,v,0.0); // this may cause error because this is an weight graph
}

void MatrixWDiGraph::InsertEdge(int u,int v,double w){
	if(!matrix[u][v]) e++;
	matrix[u][v] = true;
	weight[u][v] = w;
}
void MatrixWDiGraph::DeleteVertex(int v){
	n--;
	for(int i = 0 ; i < nodes ;i++){
		if(matrix[v][i]) e--;
		if(matrix[i][v]) e--;
		matrix[v][i] = false;
		matrix[i][v] = false;
	}	
}
void MatrixWDiGraph::DeleteEdge(int u,int v){
	if(matrix[u][v]) e--;
	matrix[u][v] = false;
	weight[u][v] = 0;
}

std::vector<int> MatrixWDiGraph::adjNodes(int u){
	std::vector<int> vec;
	for(int i = 0 ; i < nodes; i++){
		if (matrix[u][i]) vec.push_back(i);
	}
	return vec;
}



double MatrixWDiGraph::Kruskal(){
	dsu.resize(nodes);
	priority_queue<node,vector<node>,comp> queue;
	for(int u = 0 ; u < nodes;u++){
		for(int v:adjNodes(u)){
			queue.push({u,v,weight[u][v]});
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

double MatrixWDiGraph::Prim(int n){
	dsu.resize(nodes);
	priority_queue<node,vector<node>,comp> queue;
	for(int v:adjNodes(n)){
		queue.push({n,v,this->weight[n][v]});
	}
	
	double weight = 0;
	while(queue.size()){
		node k = queue.top();queue.pop();
		if (dsu.find(k.u) != dsu.find(k.v)){
			dsu.Union(k.u,k.v);
			weight += k.w;
			for(int v:adjNodes(k.v)){
				queue.push({k.v,v,this->weight[k.v][v]});
			}
		}
	}
	return weight;
}

double MatrixWDiGraph::Sollin(){
	dsu.resize(nodes);
	double weight = 0;
	vector<priority_queue<node,vector<node>,comp> > g(nodes);
	for(int i = 0 ; i < nodes; i++){
		for(int j = 0 ; j < nodes;j++){
			if(matrix[i][j]) g[i].push({i,j,this->weight[i][j]});
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


MatrixWDiGraph::~MatrixWDiGraph(){
	
}


