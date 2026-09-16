#include <vector>
#include <iostream>
using namespace std; 

using VI = vector<int>; 
using VB = vector<bool>; 

int n, inv; 
VI V; 
VB usat; 
VI invers; 

void escriu() {
	for (int i = 0; i < n; ++i) cout <<  (i ? ',' : '(') << V[i] + 1; 
	cout << ')' << endl; 
}

int count_inv(int i, int j) {
	int c = 0; 
	for(int l = 0; l < i; ++l) {
		if(V[l] > j) ++c; 
	}
	return c; 
}
	

void f(int i, int k) {
	if (i == n and k == inv) return escriu(); 
	
	for (int j = 0; j < n; ++j) {
		if (not usat[j] and k <= inv) {
			V[i] = j;
			usat[j] = true; 
			f(i+1, k + count_inv(i, j));
			usat[j] = false; 
		}
	}
		
}
	

int main () {
	cin >> n >> inv; 
	V = VI(n); 
	invers = VI(n, 0); 
	usat = VB(n, false); 
	f(0, 0);
}
