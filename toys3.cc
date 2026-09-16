#include <vector>
#include <iostream>
using namespace std; 

using VI = vector<int>;
using VB = vector<bool>;  
 

int n; 
VI V; 
VB usat1;
VB usat2;  

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
		if(i%2 == 0) {
			if(not usat1[j]) {
				V[i] = j;
				usat1[j] = true; 
				f(i+1);
				usat1[j] = false;
			} 
		}
		else {
			if(not usat2[j]) {
				V[i] = j;
				usat2[j] = true; 
				f(i+1);
				usat2[j] = false;
			}
		}
	}
}
	

int main () {
	cin >> n;
	int count = 1; 
	while(n != 0) {
		cout << "Case " << count << endl; 
		V = VI(2*n); 
		usat1 = VB(n, false); 
		usat2 = VB(n, false); 
		f(0);
		cin >> n; 
		++count; 
	}
}
