#include <iostream>
#include <vector>
using namespace std; 

using VI = vector<int>;
using VVI = vector<VI>;  
using VC = vector<char>; 
using VVC = vector<VC>; 

int n, m, f0, c0, f1, c1; 
VVC T; 
VVI usat; 
VC pas; 

void escriu() {
	int N = pas.size(); 
	for(int k = 0; k < N; ++k) cout << pas[k]; 
	cout << T[f1][c1] << endl;  
}


void f(int i, int j) {
	if(j < 0 or i < 0 or i >= n or j >= m) return;
	if(usat[i][j] == true) return; 
	
	if(i == f1 and j == c1) return escriu();  

	usat[i][j] = true; 
	pas.push_back(T[i][j]); 
	f(i+1, j); 
	f(i-1, j); 
	f(i, j+1); 
	f(i, j-1); 
	usat[i][j] = false; 
	pas.pop_back(); 
}
	

int main () {
	cin >> n >> m;
	T = VVC(n, VC(m));  
	usat = VVI(n, VI(m, false)); 
	for(int i = 0; i < n; ++i) 
		for(int j = 0; j < m; ++j) cin >> T[i][j]; 
	cin >> f0 >> c0 >> f1 >> c1; 
	
	f(f0, c0);
	
}
