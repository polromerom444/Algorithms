#include <iostream>
#include <vector>
using namespace std;

using VI = vector<int>; 
using VVI = vector<VI>;
using VS = vector<string>; 

int n, m; 
VVI M; 
VI V; 
VS nom, activitat; 
VI usada; 

void escriu() {
	for(int i = 0; i < n; ++i) cout << nom[i] << ' ' << activitat[V[i]] << endl; 
	cout << "...................." << endl; 
}

void f(int i) {
	if(i == n) return escriu(); 
	
	for(int j = 0; j < m; ++j) {
		if(M[i][j] and not usada[j]) {
			V[i] = j; 
			usada[j] = true; 
			f(i+1);
			usada[j] = false; 
		} 
	}
	
}

int main () {
	while(cin >> n) {
		V = VI(n); 
		nom = VS(n); 
		for(int i = 0; i < n; ++i) cin >> nom[i]; 
		cin >> m; 
		activitat = VS(m); 
		usada = VI(m, false); 
		for(int j = 0; j < m; ++j) cin >> activitat[j];
		M = VVI(n, VI(m)); 
		for(int i = 0; i < n; ++i) 
			for(int j = 0; j < m; ++j) cin >> M[i][j]; 
		
		f(0); 
		cout << "------------------------------" << endl; 
	}
}
