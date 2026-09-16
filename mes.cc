#include <iostream>
#include <vector>
using namespace std;

using VI = vector<int>; 
using VVI = vector<VI>; 

int n, m; 
VVI G; 
VI D; 

int dfs(int x) {
	if(G[x].size() == 0) {
		//cout << "en vertex " << x << endl; 
		return 0; 
	}
	int& d = D[x]; 
	if(d != -1) return d;
	 
	int maxim = 0; 
	for(int y : G[x]) {
		maxim = max(maxim, 1 + dfs(y)); 
	}
	
	return d = maxim; 
	
}

int main () {
	while(cin >> n >> m) {
		G = VVI(n); 
		while(m--) {
			int x, y; 
			cin >> x >> y; 
			G[x].push_back(y); 
		}
		int m = 0; 
		D = VI(n, -1); 
		for(int x = 0; x < n; ++x) {
			m = max(m, dfs(x)); 
		}
		cout << m << endl; 
	}
}
