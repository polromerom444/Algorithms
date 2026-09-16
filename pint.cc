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
VVC M; 
VVB vist; 


void omple(int i, int j, char c) {
	if(i < 0 or j < 0 or i > n - 1 or j > m - 1) return; 
	if(M[i][j] == '#' or vist[i][j]) return; 
	M[i][j] = c;
	vist[i][j] = true; 
	omple(i, j+1, c); 
	omple(i, j-1, c);	 
	omple(i+1, j, c); 
	omple(i-1, j, c); 
}

int main () {
	while(cin >> n >> m) {  
		M = VVC(n, VC(m));
		vist = VVB(n, VB(m, false));  
		for(int i = 0; i < n; ++i) 
			for(int j = 0; j < m; ++j) cin >> M[i][j]; 
		
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				char c = M[i][j]; 
				int a = c - 'a'; 
				int A = c - 'A'; 
				if((a >= 0 and a <= 25) or (A >= 0 and A <= 25)) omple(i, j, c); 
			} 
		}
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) cout << M[i][j];
			cout << endl; 
		}
		cout << endl; 
	}
}
