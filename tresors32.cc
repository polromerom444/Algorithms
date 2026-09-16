#include <iostream>
#include <vector>
using namespace std; 

using VI = vector<int>; 
using VVI = vector<VI>;
using VB = vector<bool>; 
using VVB = vector<VB>; 
using VC = vector<char>; 
using VVC = vector<VC>; 

int n, m;
VVC M;
VVB vist; 

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
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) cin >> M[i][j];
	}
	int x, y; 
	cin >> x >> y; 
	if(F(x-1, y-1)) cout << "yes" << endl; 
	else cout << "no" << endl; 
}
		
