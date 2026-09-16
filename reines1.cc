#include <vector>
#include <iostream>
using namespace std; 

using VI = vector<int>; 
using VB = vector<bool>; 

int n; 
VI V; 
VB col;
VB diag1; 
VB diag2;  

void escriu() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (j == V[i]) cout << 'Q'; 
			else cout << '.'; 
		}
		cout << endl; 
	}
	cout << endl; 
}

void f(int i) {
	if (i == n) return escriu(); 
	
	for (int j = 0; j < n; ++j) {
		int d1 = i - j + n - 1;
		int d2 = i+j;
		if (not col[j] and not diag1[d1] and not diag2[d2]) {
			V[i] = j;
			col[j] = true; 
			diag1[d1] = true; 
			diag2[d2] = true; 
			f(i+1);
			col[j] = false; 
			diag1[d1] = false; 
		    diag2[d2] = false;
		}
	}
		
}
	

int main () {
	cin >> n; 
	V = VI(n); 
	col = VB(n, false); 
	diag1 = VB(2*n - 1, false); 
	diag2 = VB(2*n - 1, false); 
	f(0);
}
