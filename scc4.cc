#include <iostream>
#include <vector>
using namespace std; 

using VI = vector<int>; 
using VVI = vector<VI>; 

VVI G, I; 
VI vist, repre, vertex; 
int temps = 0; 

void dfs1(int x) {
	if(vist[x]) return; 
	vist[x] = true; 
	for(int y : I[x]) dfs1(y);
	vertex[temps++] = x; 
}

void dfs2(int r, int x) {
	if(repre[x] != -1) return; 
	repre[x] = r; 
	for(int y : G[x]) dfs2(r, y); 
	cout << x << endl; 
}


int main () {
	int n, m; 
	cin >> n >> m; 
	G = I = VVI(n);
	vist = VI(n, false); 
	repre = VI(n, -1); 
	vertex = VI(n);  
	while(m--) {
		int x, y; 
		cin >> x >> y; 
		G[x].push_back(y); 
		I[y].push_back(x); 
	}
	for(int i = 0; i < n; ++i) dfs1(i); 

	
	int cnt = 0; 
	for(int i = n-1; i>= 0; --i) {
		int x = vertex[i]; 
		if(repre[x] == -1) {
			dfs2(x, x);
			++cnt; 
			cout << "**********************" << endl; 
		}
	}
	cout << "comp connexos " << cnt << endl; 
	for(int i = 0; i < n; ++i) cout << i << ' ' << repre[i] << endl; 

}
