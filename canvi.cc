#include <vector>
#include <iostream>
using namespace std; 

using VI = vector<int>; 

int n; 
VI V; 
VI mon; 

void escriu() {
	for (int i = 0; i < n; ++i) {
		cout << V[i]; 
	}
	cout << endl; 
}


void f(int i) {
	if (sum == n) return escriu(); 
	
	for(j = 5; j <= 0; --j) {
		if (sum + mon[j] <= n) {
			V[i] = j;
			f(i+1, sum + mon[j]);
		}
	}
}
	
	

int main () {
	cin >> n; 
	mon = VI(6); 
	mon = {1, 2, 5, 10, 20, 50};
	f(0, 0);
}
