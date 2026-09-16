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
int suma; 
VVI M; 
queue<P> alfils; 
queue<P> cavalls; 
VVB vist_a; 
VVB vist_c; 
VVB sumat; 

void recorre_alfils(int i, int j) {
	if(i < 0 or j < 0 or i > n-1 or j > m-1) return; 
	if(vist_a[i][j] or M[i][j] == -1) return; 
	vist_a[i][j] = true; 
	
	if(M[i][j] > 0 and not sumat[i][j]) {
		suma += M[i][j]; 
		sumat[i][j] = true; 
	}
	recorre_alfils(i-1, j-1); 
	recorre_alfils(i-1, j+1); 
	recorre_alfils(i+1, j-1); 
	recorre_alfils(i+1, j+1);	
}

void recorre_cavalls(int i, int j) {
	if(i < 0 or j < 0 or i > n-1 or j > m-1) return; 
	if(vist_c[i][j] or M[i][j] == -1) return; 
	vist_c[i][j] = true; 
	
	if(M[i][j] > 0 and not sumat[i][j]) {
		suma += M[i][j]; 
		sumat[i][j] = true; 
	}
	recorre_cavalls(i-1, j-2); 
	recorre_cavalls(i-2, j-1);
	recorre_cavalls(i-2, j+1);
	recorre_cavalls(i-1, j+2);
	recorre_cavalls(i+1, j+2);
	recorre_cavalls(i+2, j+1); 
	recorre_cavalls(i+2, j-1); 
	recorre_cavalls(i+1, j-2);	
}

int main () {
	while(cin >> n >> m) {
		suma = 0; 
		vist_a = VVB(n, VB(m, false)); 
		vist_c = VVB(n, VB(m, false)); 
		sumat = VVB(n, VB(m, false));
		M = VVI(n, VI(m)); 
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				char c; 
				cin >> c; 
				if(c == 'B') alfils.push(P(i, j)); 
				else if(c == 'K') cavalls.push(P(i, j)); 
				else if(c == 'T') M[i][j] = -1; 
				else if(c == '.') M[i][j] = 0; 
				else M[i][j] = int(c - '0'); 
			}
		}
		
		while(not alfils.empty()) {
			int f = (alfils.front()).first; 
			int c = (alfils.front()).second; alfils.pop(); 
			recorre_alfils(f, c); 
		}
		while(not cavalls.empty()) {
			int f = (cavalls.front()).first; 
			int c = (cavalls.front()).second; cavalls.pop(); 
			recorre_cavalls(f, c); 
		}
		cout << suma << endl; 
		
	}
}
