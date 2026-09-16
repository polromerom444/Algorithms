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

VI vist; //0 no vist, 1 bipartit e, 2 bipartit d
int n, m; 

void bfs
void F(int f, int c) {
    while(not Q.empty()) {
        int f = (Q.front()).first; 
        int c = (Q.front()).second; Q.pop(); 
        if(M[f][c] == 't') {
            dist_max = D[f][c]; 
        }
        
        if(f > 0 and M[f-1][c] != 'X' and not vist[f-1][c]) {
            Q.push(P(f-1,c)); 
			vist[f-1][c] = true; 
            D[f-1][c] = 1 + D[f][c]; 
        }
        if(c > 0 and M[f][c-1] != 'X' and not vist[f][c-1]) {
            Q.push(P(f, c-1)); 
            vist[f][c-1] = true; 
            D[f][c-1] = 1 + D[f][c]; 
        }
        if(f < n-1 and M[f+1][c] != 'X' and not vist[f+1][c]) {
            Q.push(P(f+1, c));
            vist[f+1][c] = true; 
            D[f+1][c] = 1 + D[f][c];  
        }
        if(c < m-1 and M[f][c+1] != 'X' and not vist[f][c+1]) {
            Q.push(P(f, c+1));
            vist[f][c+1] = true; 
            D[f][c+1] = 1 + D[f][c]; 
        }
    }
}

bool graf_bipartit() {
	
	
}



int main () {
	while(cin >> n >> m) {
		G = VVI(n); 
		for(int i = 0; i < m; ++i) {
			int x, y; 
			cin >> x >> y; 
			G[x].push_back(y); 
			G[y].push_back(x); 
		}
		vist(n, 0);
		bool col2 = false; 
		for(int i = 0; i < n; ++i)  
		if(graf_bipartit()) cout << "yes" << endl; 
		else cout << "no" << endl; 
}
