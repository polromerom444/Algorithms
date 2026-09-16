#include <iostream>
#include <vector>
using namespace std; 

using ll = long long; 
using VL = vector<ll>; 
using VVL = vector<VL>;  

const int N = 31; 

VVL M(N, VL(N, -1)); 

ll f(int n, int k) {
	ll& res = M[n][k]; 
	if(res != -1) return res; 
	if(k == 0 or k == n) return res = 1; 
	return res = f(n-1, k-1) + f(n-1, k); 	
}

int main () {
	int n, k; 
	while(cin >> n >> k) cout << f(n, k) << endl;
	
}
