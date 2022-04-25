#include "MatrixWDiGraph.h"
#include <vector>
#include <queue>
MatrixWDiGraph::MatrixWDiGraph(int nodes): Graph(nodes){
	matrix.resize(nodes,std::vector<bool>(nodes,false));
	weight.resize(nodes,std::vector<double>(nodes,0));
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



void MatrixWDiGraph::relax(int u,int v){
	if(dist[v] > dist[u] + weight[u][v]){
		dist[v] = dist[u] + weight[u][v];
		parent[v] = u;
	}
}
void MatrixWDiGraph::dijkstra(int source){
	initialize_single_source(source);
	DSU S(nodes);
	priority_queue<node,vector<node>,comp> Q;
	Q.push({source,-1,-1});
	while (Q.size()){
		int u = Q.top().u;Q.pop();
		if (S.find(source) != S.find(u) || S.getSize(source) == 1){
			for(int v : adjNodes(u)){
				relax(u,v);
				Q.push({v,-1,weight[u][v]});
			}
			
		}
		S.Union(source,u);
	}
	for(int i = 0 ; i < nodes;i++){
		cout << dist[i] << " ";
	}
	cout << endl;
}
bool MatrixWDiGraph::bellman_ford(int source){
	initialize_single_source(source);
	vector<node> edges;
	for (int r = 0 ; r < nodes;r++){
		for(int c = 0 ; c < nodes ;c++){
			if (matrix[r][c]) {
				edges.push_back({r,c,weight[r][c]});
			}
		}
	}
	for (int i = 0 ; i < nodes;i++){
		for (node edge:edges){
			relax(edge.u,edge.v);
		}
	}
	for(node edge:edges){
		if (dist[edge.v] > dist[edge.u] + weight[edge.u][edge.v]){
			return false;
		}
	}
	for (int i = 0 ; i < nodes;i++){
		cout << dist[i] << " ";
	}
	cout << endl;
	return true;
}
void MatrixWDiGraph::floyd_warshall(){
	int n = nodes;
	for(int i = 0 ; i < nodes;i++){
		for(int j = 0 ; j < nodes;j++){
			if (i == j) D[0][i][j] = 0;
			else if (matrix[i][j]) D[0][i][j] = weight[i][j];
			else D[0][i][j] = INT_MAX/2;
			cout << D[0][i][j] << " ";
		}
			cout << endl;
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

void MatrixWDiGraph::initialize_single_source(int source){
	for (int i = 0 ; i < nodes;i++){
		dist[i] = INT_MAX/2;
		parent[i] = -1;
	}
	dist[source] = 0;
}

double MatrixWDiGraph::EdmondsKarp(int s,int t){
	int **resdualGraph = new int*[nodes];
	for(int i = 0 ; i < nodes;i++){
		resdualGraph[i] = new int[nodes];
		for(int j = 0 ; j < nodes;j++){
			if(matrix[i][j]) resdualGraph[i][j] = weight[i][j]; // 給上 capacity 
		}
	}
	double maxflow = 0.0;
	int path[nodes];
	while(BFSfindPath(resdualGraph,path,s,t)){
		double minCapacity = findMinCost(path,t);
		maxflow += minCapacity;
		
		for(int v = t; v != s; v = path[v]){
			int u = path[v];// from u to v
			resdualGraph[u][v] -= minCapacity;
			resdualGraph[v][u] += minCapacity;
		}
	}
	
	for(int i = 0 ; i < nodes;i++){
		delete[] resdualGraph[i];
	}
	delete[] resdualGraph;
	
	return maxflow;
}


bool MatrixWDiGraph::BFSfindPath(int **resdualGraph,int *path,int s, int t){
	int visited_[nodes];
	for (int i = 0; i < nodes; i++){
        visited_[i] = 0;     // 0 表示還沒有被找到
        path[i] = -1; // refer to the prevent path
    }
    std::queue<int> q;
	q.push(s);
	visited_[s] = 1;
	while(q.size()){
		int u = q.front();q.pop();
		for(int v :adjNodes(u)){
			//adj nodes
			
			//resdual graph from u to v 
			if(resdualGraph[u][v] > 0 && !visited_[v]){
				q.push(v);
				visited_[v] = true;
				path[v] = u;
			}
		}
	} 
	return visited_[t]; // if find a path
}
double MatrixWDiGraph::findMinCost(int *path,int t){
	double minCost = 100;
	while(path[t] != -1){
		minCost = min(weight[path[t]][t],minCost);
		t = path[t];// predecessor
	}
	return minCost;
}

MatrixWDiGraph::~MatrixWDiGraph(){
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


