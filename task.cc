#include <iostream>
#include <vector>
#include <queue>
using namespace std; 

using VI = vector<int>; 
using VVI = vector<VI>; 

int main () {
	int n, m; 
	while(cin >> n >> m) { 
		VVI G(n); 
		priority_queue<int> q; 
		VI V(n, 0); 
		while(m--) {
			int x, y; 
			cin >> x >> y; 
			G[x].push_back(y); 
			++V[y]; 
		}
		for(int i = 0; i < n; ++i) {
			if(V[i] == 0) q.push(-i); 
		}
		bool primer = true; 
		while(not q.empty()) {
			if(not primer) cout << ' '; 
			primer = false; 
			int x = -q.top(); q.pop(); 
			cout << x; 
			for(int y : G[x]) {
				if(--V[y] == 0) q.push(-y);
			}		
		}
		cout << endl; 	
	}
}
