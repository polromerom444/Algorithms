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

int n, m;
int dist_max; 
VVC M;
VVB vist; 
VVI D; 

VI adjf = {1, -1, 0, 0}; 
VI adjc = {0, 0, 1, -1}; 

void insereix(int f, int c, int d) {
	
	
}

void F(int f, int c, int d) {
	if(f < 0 or c < 0 or f > n-1 or c > m-1) return;
	if(vist[f][c] == true or M[f][c] == 'X') return; 
	vist[f][c] = true; 
	if(M[f][c] == 't') dist_max = max(dist_max, d); 
	
	
	for(int i = 0; i < 4; ++i) F(f + adjf[i], c + adjc[i], d+1); 
}


int main () {
	cin >> n >> m; 
	M = VVC(n, VC(m));
	D = VVI(n, VI(m, -1)); 
	dist_max = -1; 
	vist = VVB(n, VB(m, false));  
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) cin >> M[i][j];
	}
	int x, y; 
	cin >> x >> y; 
	F(x-1, y-1, 0); 
	if(dist_max == -1) cout << "no es pot arribar a cap tresor" << endl; 
	else cout << "distancia maxima: " << dist_max << endl; 
}
	
