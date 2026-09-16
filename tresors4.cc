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


VVC M;
VVB vist; 
VVI dist; 

VI adjf = {1, -1, 0, 0}; 
VI adjc = {0, 0, 1, -1}; 


int main () {
	int n, m; 
	int dist_max = -1; 
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
	int f, c; 
	while(not Q.empty()) { 
		f = (Q.front()).first; 
		c = (Q.front()).second; Q.pop();
		vist[f][c] = true;  
		if(M[f][c] == 't') dist_max = max(dist_max, dist[f][c]); 	
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
	if(dist_max != -1) cout << "distancia maxima: " << dist_max << endl; 
	else cout << "no es pot arribar a cap tresor" << endl; 
}
		
