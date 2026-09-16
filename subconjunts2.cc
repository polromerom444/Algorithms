#include <vector>
#include <iostream>
using namespace std; 

using VI = vector<int>;
using VS = vector<string>;  

int n; 
VI V;
VS par;  

void escriu() {
	bool primer = true;
	cout << '{';
	for (int i = 0; i < n; ++i) {
		if (V[i] and primer) {
			cout << par[i];
			primer = false; 
		}
		else if (V[i] and not primer) cout << ',' << par[i];
	}
	cout << '}' << endl; 
}



void f(int i, int z, int u) {
	if (z < 0 or u < 0) return; 
	
	if (i == n) return escriu(); 
	
	V[i] = 0;
	f(i+1, z - 1, u);
	V[i] = 1; 
	f(i+1, z, u-1);	
}
	

int main () {
	int u;
	cin >> u >> n; 
	V = VI(n); 
	par = VS(n); 
	for (int i = 0; i < n; ++i) {
		cin >> par[i]; 
	}
	f(0, n - u, u);
}
