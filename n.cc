#include <iostream>
#include <vector>
#include <queue>
using namespace std; 

using VI = vector<int>; 
using VVI = vector<VI>; 
using P = pair<int, int>; 

int n, m; 
VI D, cnt; 
VVI G; 

const int INF = 1e6; 

void f() {
	priority_queue<P> Q; 
	Q.push(P(0, 0)); 
	D[0] = 0; 
	while(not Q.empty()) {
		P p = Q.top(); Q.pop(); 
		int x = p.second; 
		int d = -p.first; 
		if(d == D[x]) {
			for(int y : G[x]) {
				int d2 = 1 + D[x]; 
				if(d2 == D[y]) {
					++cnt[y]; 
					Q.push(P(-d2, y)); 
				}
				else if(d2 < D[y]) {
					D[y] = d2; 
					Q.push(P(-d2, y)); 
				}
			}
		}
	}	
}


int main () {
	while(cin >> n >> m) {
		G = VVI(n); 
		D = VI(n, INF); 
		cnt = VI(n, 0); 
		while(m--) {
			int x, y; 
			cin >> x >> y; 
			G[x].push_back(y); 		
		}
		f(); 
		for(int i = 0; i < n; ++i) {
			if(D[i] == INF) cout << i << ": -1" << endl; 
			else cout << i << ": " << D[i] << ' ' << cnt[i]+1 << endl;
		}
		cout << endl;  
	}
}
