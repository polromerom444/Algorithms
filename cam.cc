#include <iostream>
#include <vector>
#include <queue>
using namespace std; 

using VI = vector<int>; 
using VVI = vector<VI>; 
using P = pair<int, int>; 
using PP = pair<int, P>; 

VVI M, D; 
const int INF = 1e5; 
int n; 

VI adjx = {1, -1, 0, 0}; 
VI adjy = {0, 0, 1, -1}; 

void explora(int c) {
	priority_queue<PP> Q; 
	Q.push(PP(-M[c][c],P(c, c))); 
	D[c][c] = M[c][c]; 
	while(not Q.empty()) {
		PP p = Q.top(); Q.pop(); 
		int d = -p.first; 
		int i = p.second.first; 
		int j = p.second.second;
		//if(d == D[i][j]) { 
			for(int k = 0; k < 4; ++k) {
				int f = i + adjx[k]; 
				int c = j + adjy[k]; 
				if(f >= 0 and c >= 0 and f < n and c < n) {
					int d2 = d + M[f][c]; 
					if(d2 < D[f][c]) {
						D[f][c] = d2; 
						Q.push(PP(-d2, P(f, c))); 
					}
				}
			}
		//}	
	} 
	int minim = INF; 
	for(int i = 0; i < n; ++i) {
		minim = min(min(D[i][0], D[i][n-1]), minim); 
	}
	for(int j = 1; j < n - 1; ++j) {
		minim = min(min(D[0][j], D[n-1][j]), minim); 
	}
	cout << minim << endl; 
}


int main () {
	while(cin >> n) { 
		M = VVI(n, VI(n)); 
		D = VVI(n, VI(n, INF)); 
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) cin >> M[i][j]; 
		}
		int c = n/2; 
		explora(c); 
	}
}
