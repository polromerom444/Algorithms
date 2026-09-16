#include <iostream>
#include <vector>
#include <queue>
using namespace std; 

using VI = vector<int>; 
using VVI = vector<VI>;
using VB = vector<bool>; 
using VVB = vector<VB>; 
using VC = vector<char>; 
using VVC = vector<VC>;
using P = pair<int, int>;  

int n, m;
VVC M;
VVB vist; 
VVI dist; 

VI adjf = {1, -1, 0, 0}; 
VI adjc = {0, 0, 1, -1}; 


bool F(int f, int c) {
	 
	if(f < 0 or c < 0 or f > n-1 or c > m-1) return false;
	if(vist[f][c] == true) return false; 
	vist[f][c] = true; 
	if(M[f][c] == 't') return true; 
	if(M[f][c] == 'X') return false; 
	
	for(int i = 0; i < 4; ++i) {
		if(F(f + adjf[i], c + adjc[i])) return true; 
	}
	return false; 
}


int main () {
	cin >> n >> m; 
	M = VVC(n, VC(m));
	vist = VVB(n, VB(m, false)); 
	dist = VVI(n, VI(m, -1));  
	for(int i = 0; i < n; ++i) 
		for(int j = 0; j < m; ++j) cin >> M[i][j];
	int x, y; 
	cin >> x >> y; 
	
	queue<P> Q; 
	Q.push(P(x-1, y-1)); 
	dist[x-1][y-1] = 0; 
	bool found = false; 
	int f, c; 
	while(not Q.empty() and not found) { 
		f = (Q.front()).first; 
		c = (Q.front()).second; Q.pop();
		vist[f][c] = true;  
		if(M[f][c] == 't') found = true; 	
		else if(M[f][c] == '.') {
			if(f > 0 and M[f-1][c] != 'X' and not vist[f-1][c]) {
				Q.push(P(f-1,c)); 
				dist[f-1][c] = 1 + dist[f][c]; 
			}
			if(c > 0 and M[f][c-1] != 'X' and not vist[f][c-1]) {
				Q.push(P(f, c-1)); 
				dist[f][c-1] = 1 + dist[f][c]; 
			}
			if(f < n-1 and M[f+1][c] != 'X' and not vist[f+1][c]) {
				Q.push(P(f+1, c));
				dist[f+1][c] = 1 + dist[f][c];  
			}
			if(c < m-1 and M[f][c+1] != 'X' and not vist[f][c+1]) {
				Q.push(P(f, c+1)); 
				dist[f][c+1] = 1 + dist[f][c]; 
			}
		}
	}
	if(found) cout << "distancia minima: " << dist[f][c] << endl; 
	else cout << "no es pot arribar a cap tresor" << endl; 
}
		
