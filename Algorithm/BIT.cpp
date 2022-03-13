#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> vec = {6,2,4,3,1,5,3};
int MAXN = vec.size();
vector<int> bit(MAXN);

ll sum(int i) {
    ll ret = 0;
    while(i > 0) ret += bit[i], i -= i & -i; // 1-base
    return ret;
}

ll query(int l,int r){
	return sum(r)-sum(l-1);
}

void modify(int i, int val) {
    while(i <= MAXN) bit[i] += val, i += i & -i;
}

int main(){
	ll ans = 0;
	for (int i : vec){
		ans += query(i+1,MAXN);
		modify(i,1);
	}
	cout << ans << endl;	
}
