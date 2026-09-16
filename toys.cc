#include <vector>
#include <iostream>
using namespace std; 

using VI = vector<int>;
using VB = vector<bool>;  
using VVB = vector<VB>;  

int n; 
VI V; 
VVB usat; 

void escriu() {
	bool primer = true;
	for(int k = 0; k < n; ++k) {
		int p = 0; 
		if (not primer) cout << '-';
		primer = false; 
		for (int i = k; i < 3*n; i += n) {
			if(p%3 == 0) cout << char('A' + V[i]);
			else if(p%3 == 1) cout << 0 + V[i]; 
			else cout << char('a' + V[i]); 
			++p;
		}
		
	}
	cout << endl; 
	
}


void f(int i) {
	if (i == 3*n) return escriu(); 
	if (V[0] == 1) return;
	
	for(int j = 0; j < n; ++j) {
		if(not usat[i/n][j]) {
			V[i] = j;
			usat[i/n][j] = true; 
			f(i+1);
			usat[i/n][j] = false; 
		}
	}
}
	

int main () {
	cin >> n;
	int count = 1; 
	while(n != 0) {
		cout << "Case " << count << endl; 
		V = VI(3*n); 
		usat = VVB(3, VB(n, false)); 
		f(0);
		cin >> n; 
		++count; 
	}
}
