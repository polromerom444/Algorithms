#include <iostream>
#include <vector>
using namespace std; 

using ll = long long;
using VL = vector<ll>; 

const int N = 68; 
VL V(N, -1); 

ll p(int n) {
	ll& res = V[n]; 
	if(res != -1) return res; 
	if(n == 0) return res = 1; 
	res = 0; 
	for(int i = 0; i < n; ++i) res += p(i)*p(n-i-1); 
	return res; 	
}

int main () {
	int n; 
	while(cin >> n) {
		if(n%2 == 1) cout << '0' << endl; 
		else cout << p(n/2) << endl; 
	}
}
	
	
