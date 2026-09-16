#include <iostream>
#include <vector>
using namespace std; 

using VI = vector<int>; 
using VVI = vector<VI>; 

int n, m, res; 
VVI G; 
VI vist, especial; 

void dfs(int x) {
	if(vist[x]) return; 
	vist[x] = true; 
	if(especial[x]) ++res; 
	for(int y : G[x]) dfs(y); 	
}

int main () {
	while(cin >> n >> m) {
		especial = VI(n, false);
		G = VVI(n); 
		while(m--) {
			int x, y; 
			cin >> x >> y; 
			G[x].push_back(y); 
		}
		int e; 
		cin >> e; 
		while(e--) {
			int x; 
			cin >> x; 
			especial[x] = true; 
		}

		res = 0; 
		for(int i = 0; i < n; ++i) {
			if(especial[i]) {
				vist = VI(n, false); 
				dfs(i);
				--res; 
			}
		}
		cout << res << endl; 	
	}	
}
