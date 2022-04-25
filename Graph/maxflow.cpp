#include "MatrixWDiGraph.h"
#include <iostream>
using namespace std;

int main(){
	MatrixWDiGraph g(6);	
	g.InsertEdge(0, 1, 9);g.InsertEdge(0, 3, 9);
    g.InsertEdge(1, 2, 3);g.InsertEdge(1, 3, 8);
    g.InsertEdge(2, 4, 2);g.InsertEdge(2, 5, 9);
    g.InsertEdge(3, 2, 7);g.InsertEdge(3, 4, 7);
    g.InsertEdge(4, 2, 4);g.InsertEdge(4, 5, 8);
    
    cout << g.EdmondsKarp(0,5) << endl;
    
    
	MatrixWDiGraph g2(6);	
	g2.InsertEdge(0,1,16);	
	g2.InsertEdge(0,3,13);	
	g2.InsertEdge(1,2,12);	
	g2.InsertEdge(3,1,4);	
	g2.InsertEdge(2,3,9);	
	g2.InsertEdge(3,4,14);	
	g2.InsertEdge(4,2,7);	
	g2.InsertEdge(2,5,20);	
	g2.InsertEdge(4,5,4);
    cout << g2.EdmondsKarp(0,5) << endl;
    
    MatrixWDiGraph g3(4);
    g3.InsertEdge(0,1,10000);
    g3.InsertEdge(0,2,10000);
    g3.InsertEdge(1,3,10000);
    g3.InsertEdge(2,3,10000);
    g3.InsertEdge(1,2,1);
    cout << g3.EdmondsKarp(0,3) << endl;

}
