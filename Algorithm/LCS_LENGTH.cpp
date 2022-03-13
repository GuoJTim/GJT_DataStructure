#include <bits/stdc++.h>
using namespace std;

vector<vector<string> > LCS_LENGTH(string X,string Y){
	int m = X.size();
	int n = Y.size();
	vector<vector<int> > c(m+1,vector<int>(n+1));
	vector<vector<string> > b(m+1,vector<string>(n+1));
	for (int i = 1 ; i <= m ; i++){
		c[i][0] = 0;
	}
	for (int j = 1 ; j <= n ; j++){
		c[0][j] = 0;
	}
	for (int i = 1 ; i <= m ;i++){
		for (int j = 1 ; j <= n ; j++){
			
			if (X[i-1] == Y[j-1]){
				c[i][j] = c[i-1][j-1] + 1;
				b[i][j] = "¡ø";
			}
			else if (c[i-1][j] >= c[i][j-1]) {
				c[i][j] = c[i-1][j];
				b[i][j] = "¡ô";
			}else {
				c[i][j] = c[i][j-1];
				b[i][j] = "¡ö";
			}
		}
	}
	return b;
}

void PRINT_LCS(vector<vector<string> > &b,string &X,int i,int j){
	if (i == 0 || j == 0) return;
	if (b[i][j] == "¡ø"){
		PRINT_LCS(b,X,i-1,j-1);
		cout << X[i-1];
	}else if (b[i][j] == "¡ô"){
		PRINT_LCS(b,X,i-1,j);	
	}else{
		PRINT_LCS(b,X,i,j-1);
	}
	 
}

int main(){
	string x,y;
	x = "ABCBDAB";
	y = "BDCABA";
	vector<vector<string> > b = LCS_LENGTH(x,y);
	cout << "ok" << endl;
	PRINT_LCS(b,x,x.size(),y.size());
}
