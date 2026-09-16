#include <iostream>
#include <vector>
#include <queue>
using namespace std; 


using P = pair<int, int>; 
using VP = vector<P>; 
using VVP = vector<VP>;
using VI = vector<int>;  

const int INF = 1e8; 
int n, m; 
VVP G; 

void bfs(int ini) {
	VI dist(n, INF); 
	VI cost(n, INF);
	VI vist(n, false);  
	queue<P> Q; 
	Q.push(P(0,ini)); 
	dist[ini] = 0; 
	cost[ini] = 0; 
	while(not Q.empty()) {
		//for(int l : cost) cout << l << ' '; 
		//cout << endl; 
		P p = Q.front(); Q.pop(); 
		int c = p.first; 
		int x = p.second;
		if(c == cost[x]) { 
			for(P arc : G[x]) {
				int y = arc.second; 
				int c2 = c + arc.first; 
				if(dist[y] == INF) {
					dist[y] = 1 + dist[x];
					Q.push(P(c2, y)); 
					cost[y] = c2; 
				} 
				else if(dist[y] == 1 + dist[x] and c2 < cost[y]) {
					cost[y] = c2;
					Q.push(P(c2, y));  
				}
			}
			
		}		
	}
	for(int i = 0; i < n; ++i) {
		cout << i << ": "; 
		if(dist[i] == INF) cout << "no" << endl; 
		else cout << dist[i] << ' ' << cost[i] << endl; 	
	}	
	cout << "----------" << endl; 
}


int main () {
	while(cin >> n >> m) {
		G = VVP(n); 
		for(int i = 0; i < m; ++i) {
			int x, y, c; 	
			cin >> x >> y >> c; 
			G[x].push_back(P(c, y)); 
			G[y].push_back(P(c, x));		
		}	
		int vi; 
		cin >> vi; 
		bfs(vi);
	} 
}
