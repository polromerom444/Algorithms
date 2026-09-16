#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


using VI = vector<int>;
using VVI = vector<VI>;
using VVVI = vector<VVI>; 

int n, m, k; 
int inf = 1e8;
VVI T; 
VVVI R; 


int f(int i, int j, int c) {
	if(j >= m or c < 0 or i >= n) cout << "OJUUU" << endl; 
	cout << "visito posicio " << i << ' ' << j << ' ' << c << endl; 
	if(i == n-1) return T[i][j];  
	int& res = R[i][j][c]; 
	if(res != inf) return res;
	
	
	int aux = f(i+1, j, c); 
	if(j > 0) aux = min(aux, f(i+1, j-1, c)); 
	if(j < m-1) aux = min(aux, f(i+1, j+1, c)); 
	if(c > 0) {
		if(j > 0 and i < n-2) aux = min(aux, f(i+2, j-1, c-1)); 
		if(j > 1) aux = min(aux, f(i+1, j-2, c-1)); 
		if(j < m-1 and i < n-2) aux = min(aux, f(i+2, j+1, c-1)); 
		if(j < m-2) aux = min(aux, f(i+1, j+2, c-1)); 
	}
	return res = T[i][j] + aux;                          
}



int main () {
	while(cin >> n >> m >> k) {
		R = VVVI(n, VVI(m, VI(k+1, inf))); 
		T = VVI(n, VI(m)); 
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) cin >> T[i][j]; 
		}
		cout << f(0, 0, k) << endl; 
		 
		
		 int minim = f(0, 0, k); 
		 for(int l = 1; l < m; ++l) minim = min(minim, f(0, 1, k)); 
		
		 cout << minim << endl; 	
	}
}
	
