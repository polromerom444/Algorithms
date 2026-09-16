#include <iostream>
#include <vector>
using namespace std; 

using VI = vector<int>; 


const int N = 500001; 
VI R(N); 


int min(int a, int b) {
	if(a < b) return a; 
	return b; 
}
	

int f(int n) {
	if(n <= 0) return N;
	int& res = R[n]; 
	if(res != -1) return res; 
	if(n == 1 or n == 5 or n == 8 or n == 14) return res = 1; 
	return res = 1 + min(min(f(n-1), f(n-5)), min(f(n-8), f(n-14))); 
}


int main () {
	int n; 
	cin >> n; 
	R = VI(N, -1); 
	while(n != -1) {
		if(n == 0) cout << 0 << endl; 
		else cout << f(n) << endl; 	
		cin >> n; 
	}
}
		
	
