#include <iostream>
#include <vector>
using namespace std; 

using VI = vector<int>; 
using VC = vector<char>; 
using VVC = vector<VC>; 

VVC T; 
VC C; 

int n, m, k; 



void f(int i, int j, int count) {
	if(i > n-1 or j > m-1) return;
	int y = count + (T[i][j] == 'X'); 
	if(y > k) return; 
	if (y + n - i - 1 + m - j - 1 < k) return;
	if(i == n-1 and j == m-1) {
		for(char x : C) cout << x;
		cout << endl;
		return; 
	}


	
	C[i+j] = 'D'; 
	f(i+1, j, y); 
	
	C[i+j] = 'R';
	f(i, j+1, y); 
}



int main() {
	while (cin >> n >> m >> k) {
		C = VC(n + m - 2, ' '); 
		T = VVC(n, VC(m)); 
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j) cin >> T[i][j]; 
		f(0, 0, 0);
		cout << "----------" << endl;  
	}
}
	
