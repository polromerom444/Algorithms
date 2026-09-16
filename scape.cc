#include <iostream>
#include <vector>
using namespace std; 

using VC = vector<char>; 
using VVC = vector<VC>; 
using VI = vector<int>; 
using VVI = vector<VI>; 

VVC M; 
VVI R; 
int n, m; 
const int N = 1000000;

int f(int i, int j) {
    int& res = R[i][j];
	if(M[i][j] == 'X') return res = 0;
	if(res == -2) {
		for(int f = i; f < n; ++f) {
			for(int c = j; c < m; ++c) R[i][j] = -2;
		}
		return res = -2; 
	}
	if (res != -1) return res;
	if(i == 0 and j == 0) return 1; 
	if(i < 0 or j < 0) return 0; 
	if(i == 0) {
		int a = f(i, j-1); 
		if(a > N) return res = -2; 
		return res = a; 
	}
	else if(j == 0) {
		int a = f(i-1, j); 
		if(a > N) return res = -2; 
		return res = a; 
	}
	else {
		int a = f(i, j-1) + f(i-1, j);
		if(a > N) return res = -2; 
		return res = a; 		
	}
}


int main () {
	cin >> n >> m; 
	while(n != 0) {
		M = VVC(n, VC(m)); 
		for(int i= 0; i < n; ++i) 
			for(int j = 0; j < m; ++j) cin >> M[i][j];
		R = VVI(n, VI(m, -1)); 
		cout << f(n-1, m-1) << endl; 
		cin >> n >> m; 
	}
}
	
