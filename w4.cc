#include <iostream>
#include <vector>
#include <queue>
using namespace std; 

using P = pair<int, int>;
using PP = pair<int, pair<int, int>>;  
using VP = vector<P>;
using VVP = vector<VP>; 
using VI = vector<int>; 

const int INF = 1e8; 

int n; 
VVP G; 

void dijkstra(int ini, int fi) {
	VI dist(n, INF); 
	VI steps(n, INF); 
	priority_queue<PP> Q; 
	dist[ini] = 0; 
	steps[ini] = 0; 
	Q.push(PP(0, P(0, ini))); 
	while(not Q.empty()) {
		PP p = Q.top(); Q.pop(); 
		int d = -p.first; 
		int s = -p.second.first; 
		int x = p.second.second; 
		if(d == dist[x]) {
			for(P arc : G[x]) {
				int y = arc.second; 
				int d2 = d + arc.first; 
				int s2 = s + 1; 
				if(d2 < dist[y]) {
					dist[y] = d2; 
					if(s2 < steps[y]) steps[y] = s2; 
					Q.push(PP(-d2,P(-s2, y))); 
				}
			}
		}
	}
	if(dist[fi] < INF) cout << "cost " << dist[fi] << ", " << steps[fi] << " step(s)" << endl; 
	else cout << "no path from " << ini << " to " << fi << endl; 
	
	
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
