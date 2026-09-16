#include <vector>
#include <iostream>
using namespace std; 

using VI = vector<int>;
using VC = vector<char>;  
using VB = vector<bool>; 

int n; 
VI V; 
VC L; 
VB usat; 

void escriu() {
	for (int i = 0; i < 2*n; ++i) {
		cout << L[V[i]]; 
	}
	cout << endl; 
}


void f(int i) {
	if (i == 2*n) return escriu();
	 
	for(int j = 0; j < 2*n; ++j) {
		if((i%2 == 0 and j < n and not usat[j]) or 
		(i%2 == 1 and j > n - 1 and not usat[j])) {
			V[i] = j;
			usat[j] = true; 
			f(i+1);
			usat[j] = false; 
		}
	}
	
}
	

int main () {
	cin >> n; 
	V = VI(2*n);
	usat = VB(2*n, false); 
	L = VC(2*n); 
	for (int i = 0; i < 2*n; ++i) {
		cin >> L[i]; 
	} 
	f(0);
}
