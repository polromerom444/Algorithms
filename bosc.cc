#include <iostream>
#include <vector>
#include <queue>
using namespace std; 

using VI = vector<int>; 
using VVI = vector<VI>; 
using VB = vector<bool>; 
using VVB = vector<VB>; 

int n, m;
int i; 
VVI G;  
VB vist; 

void dfs(int x) {
	if(vist[x]) return; 
	vist[x] = true; 
	for(int y : G[x]) dfs(y); 
}


int main () {
	while(cin >> n >> m) {
		G = VVI(n); 
		for(int i = 0; i < m; ++i) {
			int x, y; 
			cin >> x >> y; 
			G[x].push_back(y); 
			G[y].push_back(x); 
		}
		vist = VB(n, false); 
		i = 0; 
		for(int x = 0; x < n; ++x) {
			if(not vist[x]) {
				++i; 
				dfs(x);
			} 
		}
		if(i + m == n) cout << i << endl; 
		else cout << "no" << endl; 
	}
}
