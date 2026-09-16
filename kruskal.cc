#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std; 

struct Aresta {
	int x, y, c; 
}; 

using P = pair<int, int>; 
using PP = pair<int, P>;
using VPP = vector<PP>; 
using VI = vector<int>; 
 

int n, m; 
VPP V; 
VI pare; 
priority_queue<PP> Q; 

int repre(int x) {
	if(pare[x] == -1) return x; 
	return pare[x] = repre(pare[x]); 
}

int kruskal() {
	int suma = 0; 
	sort(V.begin(), V.end(), greater<PP>()); 
	//reverse(V.begin(), V.end()); 
	int q = n; 
	pare = VI(n, -1); 

	int i = 0; 
	while(i < V.size()) {
		//PP p = Q.top(); Q.pop(); 
		int c = V[i].first; 
		int x = V[i].second.first; 
		int y = V[i].second.second; 
		int rx = repre(x); 
		int ry = repre(y); 
		if(rx != ry) {
			pare[ry] = rx; 
			suma += c; 
			pare[ry] = rx; 
			if(--q == 1) return suma; 
		}
		++i; 
	}
	return suma; 
}

int main () {
	while(cin >> n >> m) { 
		V = VPP(m); 
		for(int i = 0; i < m; ++i) {
			int x, y, c; 
			cin >> x >> y >> c; 
			V[i] = PP(c, P(x, y)); 
		}
		
		//for(auto& [x, y, c] : V) cin >> x >> y >> c; 
		cout << kruskal() << endl; 
	} 	
}
