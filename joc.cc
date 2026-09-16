#include <iostream>
#include <vector>
#include <queue>
using namespace std; 

using VI = vector<int>; 
using VVI = vector<VI>; 
using VC = vector<char>; 
using VVC = vector<VC>; 
using P = pair<int, int>; 

VI adjf = {1, -1, 0 , 0}; 
VI adjc = {0, 0, 1, -1}; 

VVC T; 
VVI D; 
queue<P> Q; 
int n, m; 

void calcula() {
	while(not Q.empty()) {
		P p = Q.front(); Q.pop();
		
		for(int l = 0; l < 4; ++l) { 
			int f = p.first + adjf[l]; 
			int c = p.second + adjc[l]; 
			
			if(f >= 0 and c >= 0 and f < n and c < m) {
				if(D[f][c] == -1 or D[f][c] > (1+D[p.first][p.second])) {
					D[f][c] = 1 + D[p.first][p.second]; 
					Q.push(P(f, c));
				}
			}
		}
	}
}
		



int main () {
	while(cin >> n >> m) {
		T = VVC(n, VC(m));
		D = VVI(n, VI(m, -1));  
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m ; ++j) {
				cin >> T[i][j]; 
				if(T[i][j] == 'T') {
					Q.push(P(i, j));
					D[i][j] = 0;  
				}
				else if(T[i][j] == 'X') D[i][j] = -2; 
			}
		}
		calcula();
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) cout << (j? " ":"") << D[i][j]; 
			cout << endl; 
		}
		cout << "----------" << endl;
	} 
}
