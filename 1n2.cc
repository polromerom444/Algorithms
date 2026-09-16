#include <vector>
#include <iostream>
using namespace std; 

using VI = vector<int>; 
using VB = vector<bool>; 

int n; 
VI V; 
VB usat; 
VB visitat; 

void escriu() {
	for (int i = 0; i < n; ++i) cout <<  (i ? ',' : '(') << V[i] + 1; 
	cout << ')' << endl; 
}


void f(int i, int count) {
	if (count == n) return escriu(); 
	if(visitat[i]) return; 
	
	for (int j = 0; j < n; ++j) {
		if (not usat[j] and j != i) {
			V[i] = j;
			usat[j] = true;
			visitat[i] = true ;
			f(j, count+1);
			usat[j] = false;
			visitat[i] = false;  
		}
	}
		
}
	

int main () {
	cin >> n; 
	V = VI(n); 
	usat = VB(n, false);
	visitat = VB(n, false);
	if(n == 1) cout << "(1)" << endl;   
	else f(0, 0);
}
