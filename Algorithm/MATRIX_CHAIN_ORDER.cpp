#include <bits/stdc++.h>
using namespace std;
//typedef struct matrix{
//	int r;
//	int c;
//};


vector<vector<int> >  MATRIX_CHAIN_ORDER(vector<int> p){
	int n = p.size()-1;
	vector<vector<int> > m(n+1,vector<int>(n+1)),s(n+1,vector<int>(n+1)); // 1..n
	for (int i = 1 ; i <= n ; i++){
		m[i][i] = 0;
	}
	for (int l = 2 ; l <= n ; l++){
		for (int i = 1 ; i <= n - l + 1 ; i++){
			int j = i + l - 1;
			m[i][j] = INT_MAX;
			for (int k = i ; k <= j - 1 ;k++){
				int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
				
				if (q < m[i][j]){
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
	cout << endl;
	for (int i = 1 ; i <= n;i++){
		for(int j = 1 ; j <= n;j++){
			cout << "\t" << m[i][j];
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 1 ; i <= n;i++){
		for(int j = 1 ; j <= n;j++){
			cout << "\t" << s[i][j];
		}
		cout << endl;
	}
	return s;
}

void PRINT_OPTIMAL_PARENTS(vector<vector<int> > &s,int i,int j){
	if (i == j){
		cout << "A" << i;
	}else {
		cout << "(";
		PRINT_OPTIMAL_PARENTS(s,i,s[i][j]);
		PRINT_OPTIMAL_PARENTS(s,s[i][j]+1,j);
		cout << ")";
	}
}


int main(){
//	matrix A1,A2,A3,A4,A5,A6,empty;
//	empty.c = 0;empty.r = 0;
//	A1.r = 30;A1.c = 35;
//	A2.r = 35;A2.c = 15;
//	A3.r = 15;A3.c = 5;
//	A4.r = 5;A4.c = 10;
//	A5.r = 10;A5.c = 20;
//	A6.r = 20;A6.c = 25;
	vector<int> p_array = vector<int>();
	p_array = {30,35,15,5,10,20,25};	
	vector<vector<int> > mp = MATRIX_CHAIN_ORDER(p_array);
	PRINT_OPTIMAL_PARENTS(mp,1,6);
}
