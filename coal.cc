#include <iostream>
#include <vector>
using namespace std; 

using VI = vector<int>; 

int n, k; 
VI V, P, S; 

void escriu() {
	
	bool primer = true; 
	for(int i = 0; i < n; ++i) {
		if(V[i] and primer) {
			cout << '{' << i+1; 
			primer = false; 
		}
		else if(V[i]) cout << ", " << i+1; 
	}
	cout << '}' << endl; 	
}

bool redundant(int suma) {
	for(int i = 0; i < n; ++i) {
		if(V[i] and suma - P[i] >= k) return true;
	}
	return false; 
}
		

void f(int i, int suma) {
	if(suma >= k) {
		for(int j = i; j < n; ++j) V[j] = 0; 
		if(not redundant(suma)) escriu(); 
		return ; 
	}
	if(i == n) return; 
	if(i > 0 and suma + (S[n-1]-S[i-1]) < k) return; 
	
	V[i] = 1; 
	f(i+1, suma + P[i]); 
	V[i] = 0; 
	f(i+1, suma); 
		
}

int main () {
	while(cin >> k >> n) {
		V = VI(n);
		P = VI(n); 
		S = VI(n, 0); 
		for(int i = 0; i < n; ++i) {
			cin >> P[i];
			if(i == 0) S[i] = P[i]; 
			else S[i] += S[i-1] + P[i]; 
		}
		f(0, 0);  
		cout << "----------" << endl; 	
	}	
}
