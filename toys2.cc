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
	int m = 0;  
	for(int i = 0; i < 2*n; ++i) {
		if(primer) {
			cout << 'A'; 
			primer = false; 
		}
		else if(i%2 == 0) {
			cout << '-' << char('B' + m); 
			++m;
		}
		if(i%2 == 0) cout << V[i];
		else cout << char('a' + V[i]); 
	}
	cout << endl; 
}



void f(int i) {
	if (i == 2*n) return escriu(); 

	for(int j = 0; j < n; ++j) {
		if(not usat[i%2][j]) {
			V[i] = j;
			usat[i%2][j] = true; 
			f(i+1);
			usat[i%2][j] = false; 
		}
	}
}
	

int main () {
	cin >> n;
	int count = 1; 
	while(n != 0) {
		cout << "Case " << count << endl; 
		V = VI(2*n); 
		usat = VVB(2, VB(n, false)); 
		f(0);
		cin >> n; 
		++count; 
	}
}
