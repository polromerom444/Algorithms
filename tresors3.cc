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

int main () {
	cin >> n >> m; 
	M = VVC(n, VC(m));
	vist = VVB(n, VB(m, false)); 
	for(int i = 0; i < n; ++i) 
		for(int j = 0; j < m; ++j) cin >> M[i][j];
	int x, y; 
	cin >> x >> y; 
	queue<P> Q; 
	Q.push(P(x-1, y-1)); 
	
	int tresors = 0;  
	int f, c; 
	while(not Q.empty()) { 
		f = (Q.front()).first; 
		c = (Q.front()).second; Q.pop();
		vist[f][c] = true;  
		if(M[f][c] == 't') ++tresors; 
		if(f > 0 and M[f-1][c] != 'X' and not vist[f-1][c]) Q.push(P(f-1,c)); 
		if(c > 0 and M[f][c-1] != 'X' and not vist[f][c-1]) Q.push(P(f, c-1)); 
		if(f < n-1 and M[f+1][c] != 'X' and not vist[f+1][c]) Q.push(P(f+1, c));
		if(c < m-1 and M[f][c+1] != 'X' and not vist[f][c+1]) Q.push(P(f, c+1)); 
	}
	cout << tresors << endl; 
}
		
