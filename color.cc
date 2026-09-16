#include <iostream>
#include <vector>
#include <queue>
using namespace std; 

using VI = vector<int>;
using VVI = vector<VI>; 

int n, m; 
VI color; 
VVI G; 

bool bfs(int ini) {
	queue<int> Q; 
	Q.push(ini);  
	color[ini] = 0; 
	while(not Q.empty()) {
		int x = Q.front(); Q.pop(); 
		for(int y : G[x]) {
			if(color[y] == color[x]) {
				return false;
			}

			if(color[y] == -1) {
				color[y] = 1 - color[x]; 
				Q.push(y); 
			} 
		}
 
	}
	return true; 
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
		color = VI(n, -1); 
		bool es = true; 
		int i = 0; 
		while(i < n and es) {
			if(color[i] == -1) {
				es = bfs(i);
			} 
			++i; 
		}
		if(es) cout << "yes" << endl; 
		else cout << "no" << endl;
	}
}
