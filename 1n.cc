#include <vector>
#include <iostream>
using namespace std; 

using VI = vector<int>; 
using VB = vector<bool>; 
using VC = vector<char>; 

int n, m; 
VI V; 
VB usat;
VB cons; 
VC par;  

void escriu() {
	for (int i = 0; i < m; ++i) cout <<  (i ? ',' : '(') << V[i]; 
	cout << ')' << endl; 
}


void f(int i) {
	if (i == m) return escriu(); 
	
	for (int j = 0; j < m; ++j) {
		bool consonant = true; 
		if (consonant) {
			if (not usat[j] and cons[j]) {
				V[i] = j;
				usat[j] = true; 
				f(i+1);
				usat[j] = false; 
				consonant = false; 
			}
		}
		else if (not consonant) {
			if (not usat[j] and not cons[j]) {
				V[i] = j;
				usat[j] = true; 
				f(i+1);
				usat[j] = false; 
				consonant = false; 
			}
		}
			
	}
		
}
	

int main () {
	cin >> n; 
	m = 2*n; 
	V = VI(m); 
	usat = VB(m, false);
	cons = VB(m, false); 
	for (int i = 0; i < n; ++i) {
		cons[i] = 0; 
	}
	par = VC(m); 
	for (int i = 0; i < m; ++i) {
		cin >> par[i];
	}
	f(0);
}
