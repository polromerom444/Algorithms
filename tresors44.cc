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

queue<P> Q; 

int n, m;
VVC M;
VVB vist; 
int dist_max; 
VVI D; 

VI adjf = {1, -1, 0, 0}; 
VI adjc = {0, 0, 1, -1}; 


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


int main () {
    dist_max = -1; 
	cin >> n >> m; 
	M = VVC(n, VC(m));
    D = VVI(n, VI(m, -1));  
	vist = VVB(n, VB(m, false));  
	for(int i = 0; i < n; ++i) 
		for(int j = 0; j < m; ++j) cin >> M[i][j];
	int x, y; 
	cin >> x >> y; 
    Q.push(P(x-1, y-1));
    D[x-1][y-1] = 0; 
	F(x-1, y-1); 
	if(dist_max != -1) cout << "distancia maxima: " << dist_max << endl; 
    else cout << "no es pot arribar a cap tresor" << endl; 
}
