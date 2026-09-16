#include <iostream>
#include <vector>
using namespace std;

using VI = vector<int>; 
using VVI = vector<VI>; 

int n, m; 
VVI G; 
VVI M; 
VI vist;

void dfs(int i, int x) {
	 if(vist[x]) return;
	 vist[x] = true; 
	 M[i][x] = true; 
	 for(int y : G[x]) dfs(i, y); 
}

int main () {
	while(cin >> n >> m) {
		G = VVI(n); 
		M = VVI(n, VI(n, 0)); 
		while(m--) {
			int x, y; 
			cin >> x >> y; 
			G[x].push_back(y); 
		}
		for(int i = 0; i < n; ++i) {
			vist = VI(n, false); 
			dfs(i, i); 
		}
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) cout << (j? " " : "") << M[i][j]; 
			cout << endl; 
		}
		cout << "--------------------" << endl; 
	}
}
