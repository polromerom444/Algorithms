#include <iostream>
#include <vector>
#include <queue>
using namespace std; 


using P = pair<double,double>; 
using PP = pair<P, double>; 
using VPP = vector<PP>; 
using VI = vector<int>; 
using VVI = vector<VI>; 

double d;
int n; 
VVI G;  

bool pots_passar(int i, int j, const VPP& V) {
	double x1, x2, y1, y2, r1, r2; 
	x1 = V[i].first.first; 
	y1 = V[i].first.second; 
	r1 = V[i].second; 
	x2 = V[j].first.first; 
	y2 = V[j].first.second; 
	r2 = V[j].second; 
	double dx = (x1 - x2)*(x1 - x2); 
	double dy = (y1 - y2)*(y1 - y2); 
	double R = d + r1 + r2; 
	if(dx + dy < R*R) return true; 
	return false; 
	
}

int BFS() {
	VI dist(n, -1); 
	queue<int> Q; 
	Q.push(0); 
	dist[0] = 0; 
	while(not Q.empty()) {
		int x = Q.front(); Q.pop(); 
		if(x == n-1) return dist[x]; 
		for(int y : G[x]) {
			if(dist[y] == -1) {
				dist[y] = 1 + dist[x]; 
				Q.push(y); 
			}
		}
	}
	return -1; 
}

int main () { 
	while(cin >> n >> d) {
		VPP V(n); 
		double x, y, r; 
		for(int i = 0; i < n; ++i) {
			cin >> x >> y >> r; 
			V[i] = PP(P(x, y), r); 	 			
		}
		G = VVI(n);  
		for(int i = 1; i < n; ++i) {
			for(int j = 0; j < i; ++j) {
				if(pots_passar(i, j, V)) {
					G[j].push_back(i);
				}
			}
		}
		int res = BFS(); 
		if(res == -1) cout << "Xof!" << endl; 
		else cout << res << endl; 	
	}	
}
