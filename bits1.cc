#include <vector>
#include <iostream>
using namespace std; 

const int N = 151; 
using ll = long long;
using VL = vector<ll>; 
using VVL = vector<VL>; 

VVL Z(N, -1); 
VVL U(N, -1);

ll u(int nz, int nu); 

ll z(int nz, int nu) {
	ll& res = Z[n]; 
	if(res != -1) return res; 
	if(n == 0 or n == 1) return res = 1; 
	return res = u(nz-1, nu); 
}

ll u(int nz, int nu) {
	ll& res = U[n];  
	if(res != -1) return res; 
	if(n == 0 or n == 1) return res = 1; 
	return res = z(nz, nu) + u(nz, nu); 

}

int main() {
	int zeros, uns; 
	while(cin >> zeros >> uns) {
		if(zeros == 0 or uns == 0) cout << 1 << endl; 
		else cout << z(zeros, uns) + u(zeros, uns) << endl; 
	}
} 
	
	
