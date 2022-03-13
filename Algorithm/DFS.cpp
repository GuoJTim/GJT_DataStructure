#include <bits/stdc++.h>
using namespace std;

enum color{
	WHITE = 0,
	GRAY = 1,
	BLACK = 2
};

typedef struct vertex{
	int d;
	int f;
	color color;
	vertex *pi;
	string name;
};

class Graph{
	public:
		vector<vertex*> vertexs;
		vector<vector<bool> > adjMatrix;
		Graph(int nodes){
			adjMatrix = vector<vector<bool> >(nodes,vector<bool>(nodes,0));
		}
		void connect(vertex *from,vertex *to){
			auto result = find(vertexs.begin(),vertexs.end(),from);
			int fromI;
			if (result == vertexs.end()){
				fromI = vertexs.size();
				vertexs.push_back(from);
			}else{
				fromI = (int)(result - vertexs.begin());	
			}
			 result = find(vertexs.begin(),vertexs.end(),to);
			int toI;
			if (result == vertexs.end()){
				toI = vertexs.size();
				vertexs.push_back(to);
			}else{
				toI = (int)(result - vertexs.begin());	
			}
			adjMatrix[fromI][toI] = true;
		}
		vector<vertex*>& getV(){
			return vertexs;
		}
		vector<vertex*> getAdj(vertex* node){
			auto result = find(vertexs.begin(),vertexs.end(),node);
			int index = result - vertexs.begin();
			vector<vertex*> v;
			for (int i = 0 ; i < adjMatrix.size();i++){
				if (adjMatrix[index][i] == true){
					v.push_back(vertexs[i]);
				}
			}
			return v;
		}
};


void DFS_VISIT(Graph g,vertex* u,int &time){
	cout << "first visited " << u->name << endl; 
	time = time + 1;
	u->d = time;
	u->color = GRAY;
	vector<vertex*> adj = g.getAdj(u);
	for (vertex* v : adj){
		if (v->color == WHITE){
			v->pi = u;
			DFS_VISIT(g,v,time);
		}
	} 
	u->color = BLACK;
	time = time + 1;
	u->f = time;
	cout << "end visited " << u->name << endl; 
}

void DFS(Graph g,int & time){
	vector<vertex*> vertexs = g.getV();
	for (vertex* v : vertexs){
		v->color = WHITE;
		v->pi = NULL;
	}
	time = 0;
	for (vertex*v : vertexs){
		if (v->color == WHITE){
			DFS_VISIT(g,v,time);
		} 
	}
	
}


int main(){
	Graph g = Graph(6);
	vertex a,b,c,d,e,f;
	a.name = "a";b.name = "b";c.name = "c";d.name = "d";e.name = "e";f.name = "f";
	g.connect(&a,&b);
	g.connect(&b,&c);
	g.connect(&c,&f);
	g.connect(&a,&d);
	g.connect(&d,&b);
	g.connect(&e,&b);
	g.connect(&f,&e);
	//cout << g.getAdj(&a).size();
	//cout << (g.getAdj(&a)[1] == &d) << endl;
	vertex *start = &a;
	
	int time = 0;
	DFS(g,time);
	
}
