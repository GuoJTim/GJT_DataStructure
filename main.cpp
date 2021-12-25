#include <iostream>
#include "Polynomial/Polynomial.h"
using namespace std;

int main(){
	Polynomial a,b;
	cin >> a;
	cin >> b;
	Polynomial c = a+b;
	cout << "finished" << endl;
	cout << c;
}    
