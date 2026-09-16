#include <iostream>
#include <vector>
#include <queue>
using namespace std; 

using VI = vector<int>; 
using VVI = vector<VI>; 

int n, m, count;  
VVI G, A; 
VI u; 


void busca(int k, int x, int l) {
	if(k >= 3 and A[l][x]) ++count; 
	if(k == n) return; 
	for(int w : G[l]) {
		if(w > x and not u[w]) {
			u[w] = true; 
			busca(k+1, x, w); 
			u[w] = false; 		
		}
	}
	
}

int main () {
	while(cin >> n >> m) {
		G = VVI(n); 
		A = VVI(n, VI(n, false)); 
		u = VI(n, false); 
		for(int k = 0; k < m; ++k) {
			int x, y; 
			cin >> x >> y; 
			G[x].push_back(y); 
			G[y].push_back(x);
			A[x][y] = true; 
			A[y][x] = true;  
		}
		count = 0; 
		for(int i = 0; i < n; ++i) {
			u[i] = true; 
			busca(1, i, i); 
			u[i] = false; 
		}
		cout << count/2 << endl; 
	}
}
