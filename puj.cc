#include <iostream>
#include <vector>
using namespace std; 

using ll = long long int; 
using VI = vector<ll>; 
using VVI = vector<VI>; 


VI R; 
int n; 


int f(int n) {
	if(n == 0) return 1; 
	ll r = 0; 
	for(int i = 0; i < n; ++i) {
		r += f(i)*f(n-i-1); 
	}
	return r; 
}


int main () { 
	while(cin >> n) cout << f(n) << endl; 
}
