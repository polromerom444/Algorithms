#include <vector>
#include <iostream>
using namespace std; 

using VI = vector<int>; 
using VC = vector<char>; 
using VB = vector<bool>; 
using VVB = vector<vector<bool>>; 

int n; 
VI V; 
VC especies; 
VB usat; 
VVB incompatible; 


void escriu() {
	for (int i = 0; i < n; ++i) {
		cout << V[i]; 
	}
	cout << endl; 
}


void f(int i) {
	if (i == n) return escriu(); 
	
	for (int j = 0; j < n; ++i) {
		if(not usat[j]) {
			V[i] = j; 
			usat[j] = true; 
			f(i+1);
			usat[j] = false; 
		}
	}
		
}
	

int main () {
	cin >> n; 
	V = VI(n); 
	especies = VC(n); 
	for (int i = 0; i < n; ++i) {
		cin >> especies[i]; 
	}
	usat = VB(n);
	incompatible = VVB(n, VB(n)); 
	
	f(0);
}
