#include <iostream>
#include <vector>
using namespace std; 

using VI = vector<int>;

int n, t;
int sum;  
VI V; 

void escriu() {
	for (int i = 0; i < n; ++i) {
		cout << V[i];
	} 
	cout << endl; 
}


void f(int i, int sum) {
	if (i == n and sum == 1) return escriu(); 
	
	for (int j = 0; j <= t; ++j) {
		V[i] = j; 
		f(i+1, sum + j);
	}
}


int main () {
	cin >> n >> t;
	sum = 0; 
	V = VI(n);
	f(0, 0);
}
	 
	
	
