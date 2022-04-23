#include "Graph.h"
#include "../DisjoinUnionSet/DSU.h"
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;

Graph::Graph(int nodes){
	this->nodes = nodes;
	n = nodes;
}

Graph::~Graph(){
	
} 
void Graph::DFS(){
	visited = new bool[nodes];
	fill(visited,visited+nodes,false);
	DFS(0);
	delete [] visited;
}

void Graph::DFS(const int v){
	cout << v << " ";
	visited[v] = true;
	for (int w : adjNodes(v)){
		if (!visited[w]) DFS(w);
	}
}

void Graph::BFS(int v){
	visited = new bool[nodes];
	fill(visited,visited+nodes,false);
	visited[v] = true;
	queue<int> q;
	q.push(v);
	while(q.size()){
		v = q.front();
		cout << "visited " << v << endl;
		q.pop();
		for(int w : adjNodes(v)){
			if(!visited[w]){
				q.push(w);
				visited[w] = true;
			}
		}
	}
	delete [] visited;
}

void Graph::Components(){
	visited = new bool[nodes];
	fill(visited,visited+nodes,false);
	for(int i = 0 ; i < nodes;i++){
		if(!visited[i]){
			DFS(i);
			cout << "new component" << endl;
			//output
		}
	}
	delete [] visited;
}

#include <iomanip>

void Graph::DfnLow(const int x){
	num = 1;
	dfn = new int[nodes];
	low = new int[nodes];
	fill(dfn,dfn+nodes,0);
	fill(low,low+nodes,0);
	DfnLow(x,-1);
	cout << setw(7) << "Vertex";
	for(int i = 0 ; i < nodes;i++){
		cout << setw(3) << i;
	}
	cout << endl;
	cout << setw(7) << "dfn";
	for(int i = 0 ; i < nodes;i++){
		cout << setw(3) << dfn[i];
	}
	cout << endl;
	cout << setw(7) << "low";
	for(int i = 0 ; i < nodes;i++){
		cout << setw(3) << low[i];
	}
	cout << endl;
	
	delete [] dfn;
	delete [] low;
}

void Graph::DfnLow(const int u,const int v){
	dfn[u] = low[u] = num++;
	for(int w : adjNodes(u)){
		if(dfn[w] == 0){
			DfnLow(w,u);
			low[u] = min(low[u],low[w]);
		}
		else if (w!=v) low[u] = min(low[u],dfn[w]); //back edge
	}
}

void Graph::Biconnected(){
	num = 1;
	s = std::stack<pair<int,int>>();
	dfn = new int[nodes];
	low = new int[nodes];
	fill(dfn,dfn+nodes,0);
	fill(low,low+nodes,0);
	Biconnected(0,-1);
	
	delete [] dfn;
	delete [] low;
}


void Graph::Biconnected(const int u,const int v){
	dfn[u] = low[u] = num++;
	for(int w : adjNodes(u)){
		if((v!=w) && (dfn[w] < dfn[u])) {
			s.push({u,w});
		}
		if(dfn[w] == 0){
			Biconnected(w,u);
			low[u] = min(low[u],low[w]);
			if(low[w] >= dfn[u]){
				cout << "New Biconnected Component: " << endl;
				int x,y;
				do{
					x = s.top().first;
				    y = s.top().second;
				    s.pop();
				    cout << x << ", " << y << endl;
				}while(x != u || y != w );
			}
			
		}
		else if (w!=v) low[u] = min(low[u],dfn[w]); //back edge
	}
}



