#include <vector>
#include <iostream>
using namespace std; 

using VI = vector<int>; 

int n; 
VI V; 

void escriu() {
	cout << V[0]; 
	for (int i = 1; i < n; ++i) {
		cout << ' ' << V[i]; 
	}
	cout << endl; 
}


void f(int e, int d) {
	if(i == n) return escriu(); 
	
	V[i] = 0;
	f(i+1);
	V[i] = 1; 
	f(i+1);	
}
	

int main () {
	cin >> n; 
	V = VI(n);
	for(int i=0; i < n; ++i) {
		cin >> V[i]; 
	} 
	f(0);
}
