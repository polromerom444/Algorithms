#include <iostream>
#include <vector>
#include <queue>
using namespace std; 

using VI = vector<int>; 
using VVI = vector<VI>;
using VB = vector<bool>; 

int n, m; 
VI V;
VVI G; 
VB vist;  
bool te_sol; 

void escriu() {
	te_sol = true; 
	int suma = 0; 
	for(int x : V) {
		//cout << x; 
		suma += 1 + x; 
	}
	cout << suma << endl; 
}

bool bfs(int ini) {
	
	queue<int> Q; 
	Q.push(ini);  
	while(not Q.empty()) {
		int x = Q.front(); Q.pop(); 
		vist[x] = true; 
		int count = 0; 
		for(int y : G[x]) {
			if(V[y] == V[x]) {
				++count; 
				if(count > 1) return false;
			}
			if(not vist[y]) {
				Q.push(y); 
			} 
		}
	}
	return true; 
}

bool es_solu() {
	vist = VB(n, false); 
	for(int i = 0; i < n; ++i) {
		if(not vist[i]) {
			bool sol = bfs(i); 
			//cout << "es  : " << sol << endl; 
			if(not sol) return false; 
		}

	}
	return true; 
}

bool f(int i, int u) {
	if(i == n) {
		 if(u == 0 and es_solu()) {
			 escriu();
			 return true; 
		 }
		 return false;  
	}
	
	if(n - i < u) return false; 

	V[i] = 0; 
	if(f(i+1, u)) return true;  
	if(u > 0) {
		V[i] = 1; 
		if(f(i+1, u-1)) return true; 
	}
	return false;
}


int main () {
	while(cin >> n >> m) {
		te_sol = false; 
		G = VVI(n); 
		V = VI(n); 
		for(int i = 0; i < m; ++i) {
			int x, y; 
			cin >> x >> y; 
			G[x].push_back(y); 
			G[y].push_back(x); 
		}
		int u = 0; 
		bool trobat = false;  
		while(u <= n/2 + 1 and not trobat) {
			if(f(0, u)) trobat = true;
			++u;   
		}
		if(not te_sol) cout << "NO" << endl; 
		
	}	
}
