#include <iostream>
#include <vector>
using namespace std; 

using VC = vector<char>;
using VI = vector<int>;
using VB = vector<bool>;

int n, r; 
VI V; 

void escriu() {
	for(int i = 0; i < n; ++i) cout << V[i]; 
	cout << endl; 
}

bool es_multiple() {
	int number = V[0]; 
	for(int i = 1; i < n; ++i) {
		number = 10*number + V[i]; 
	}
	if(number%7 == 0) return true; 
	return false; 
}

void f(int i) {
	if(i == n and es_multiple()) return escriu(); 
	
	for(int j = 0; j < 10; ++j) {
		V[i] = j; 
		f(i+1); 
	}	
}


int main () {
	while(cin >> n >> r) {
		V = VI(n); 
		f(0); 
		
		
	}
	
	
	
}
