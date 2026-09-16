#include <iostream>
#include <vector>
using namespace std; 

using VI = vector<int>; 

VI V; 
int n; 


void escriu() {
	for (int j = 0; j < n; ++j) cout << (j ? " " : "") << V[j]; 
	cout << endl; 
	
	
	
}


void f(int i) {
	if(i == n) return escriu(); 
	
	V[i] = 0; 
	f(i + 1);
	V[i] = 1; 
	f(i+1);	
	
}


int main () {
	cin >> n; 
	V = VI(n); 
	f(0); 
	
	
}
