#include <iostream>
#include <vector>
#include <queue>
using namespace std; 

using P = pair<int, int>; 
using VP = vector<P>;
using VVP = vector<VP>; 
using VI = vector<int>; 

const int INF = 1e8; 

int n; 
VVP G; 

void dijkstra(int ini, int fi) {
	VI dist(n, INF); 
	priority_queue<P> Q; 
	dist[ini] = 0; 
	Q.push(P(0, ini)); 
	while(not Q.empty()) {
		P p = Q.top(); Q.pop(); 
		int d = -p.first; 
		int x = p.second; 
		if(d == dist[x]) {
			if(x == fi) {
				cout << dist[fi] << endl; 
				return; 
			}
			for(P arc : G[x]) {
				int y = arc.second; 
				int d2 = d + arc.first; 
				if(d2 < dist[y]) {
					dist[y] = d2; 
					Q.push(P(-d2, y)); 
				}
			}
		}
	} 
	cout << "no path from " << ini << " to " << fi << endl; 
	
	
}


int main() {
	int m; 
	while(cin >> n >> m) { 
		G = VVP(n);  
		for(int i = 0; i < m; ++i) {
			int x, y, c; 
			cin >> x >> y >> c;  
			G[x].push_back(P(c, y)); 
		}
		int ini, fi; 
		cin >> ini >> fi; 
		dijkstra(ini, fi); 
	}	
}
