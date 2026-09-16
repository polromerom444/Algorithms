#include <iostream>
#include <vector>
#include <queue>
using namespace std; 

using P = pair<int, int>;
using VI = vector<int>; 
using VVI = vector<VI>;
using VB = vector<bool>;  
using VVB = vector<VB>; 

int n, m; 
VVI D; 
VVB pers; 

void busca() {
	queue<P> Q; 
	Q.push(P(0,0)); 
	
	
	
}

int main () {
	while(cin >> n >> m) {
		D = VVI(n, VI(m, -1)); 
		pers = VVB(n, VB(m, false)); 
		bool esta = false; 
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				char c; 
				cin >> c; 
				if(c == 'T') {esta = true; D[i][j] = 0; }
				else if(c == '#') D[i][j] = -1; 
				else if(c == 'P') pers[i][j] = true; 
			}
		}
		if(not esta) cout << "El telecos ha fugit." << endl; 
		else busca();
		
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) cout << D[i][j] << ' '; 
			cout << endl; 
		}  
	}
}
	
