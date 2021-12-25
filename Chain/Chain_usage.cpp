#include "Chain.h"
#include <iostream>
using namespace std;

int main(){
	int int_value = 7; // for a int value
	
	ChainNode<int> *a_node = new ChainNode<int>(int_value);
	
	Chain<int> chain;
	chain.Insert(0,4);//insert value 4
	chain.Print(); // print value
	
	{
		//using Insert as insert back
		Chain<int> chain_b;
		chain_b.Insert(chain_b.Length(),1);
		chain_b.Insert(chain_b.Length(),2);
		chain_b.Insert(chain_b.Length(),3);
		chain_b.Insert(chain_b.Length(),4);
		chain_b.Print();
		
	}
	
	Chain<int> chain_c;
	chain_c.Insert(0,a_node);//insert a node 
	chain_c.InsertBack(new ChainNode<int>(101));// insert back
	chain_c.Print();
	
}
