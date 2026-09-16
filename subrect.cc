#include <iostream>
#include <vector>
using namespace std; 

using ll = long long; 
using VL = vector<ll>; 
using VVL = vector<VL>; 
using VI = vector<int>; 
using VVI = vector<VI>; 

VI l(26); 
VVI M; 
VVL R; 
const int N = 501; 
int n, m; 

/*
f(int i, int j) {
	
	
}
*/

int main () {
	l[0] = 1; 
	for(int i = 1; i < 26; ++i) {
		l[i] = l[i-1]+ i+1; 
	}
	string s;
	n = 1; 
	cin >> s; 
	m = s.size(); 
	M = VVI(N, VI(m));
	R = VVL(N, VL(m));
	for(int j = 0; j < m; ++j) { 
		M[0][j] = l[int(s[j]-'A')]; 
	}
	while (cin >> s) {
		for(int j = 0; j < m; ++j) {
			M[n][j] = l[int(s[j]-'A')];   
		}
		++n; 
	}
	for (int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) { 
			if(i == 0 and j == 0) R[i][j] = M[i][j]; 
			else if(i > 0 and j == 0) R[i][j] = M[i][j] + R[i-1][j]; 
			else if(i == 0 and j > 0) R[i][j] = M[i][j] + R[i][j-1]; 
			else R[i][j] = M[i][j] + R[i-1][j] + R[i][j-1] - R[i-1][j-1]; 
			if(j == m-1) cout << R[i][j]; 
			else cout << R[i][j] << ' '; 
						
		}
		cout << endl; 
	}
	 

}
		
	
