#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

using VC = vector<char>;
using VI = vector<int>;
using VB = vector<bool>;

VI V; 
VC C, R; 
VB usat; 
int n;  

void escriu() {
	for(int i = 0; i < n/2; ++i) cout << R[i]; 
	cout << endl; 
}

void f(int i) {
	if(i == n/2) return escriu();
	
	for(int j = 0; j < n; ++j) {
		if(not usat[j]) {
			R[i] = C[j]; 
			usat[j] = true; 
			f(i+1);
			usat[j] = false; 
		}
	} 
}



int main () {
	while(cin >> n) {
		C = VC(n); 
		V = VI(n);
		R = VC(n/2); 
		usat = VB(n, false);  
		for(int i = 0; i < n; ++i) cin >> C[i];
		sort(C.begin(), C.end()); 
		f(0);
		cout << "----------" << endl;   	
	}
}
