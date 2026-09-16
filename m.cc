#include <iostream>
#include <vector>
using namespace std; 

using VD = vector<double>; 
using VVD = vector<VD>;

int n, k; 

VD P; 
VVD R; 

double f(int i, int c) {
	if(i == n and c == k) return 1; 
	else if(i == n) return 0; 
	if(c > k) return 0; 
	if(n - i + 1 < k - c) return 0; 
	
	double& res = R[i][c]; 
	if(res != -1) return res; 
	
	return res = P[i]*f(i+1, c+1) + (1-P[i])*f(i+1, c); 
}

int main () {
	cout.setf(ios::fixed);
    cout.precision(4);
    
    while(cin >> n >> k) {
		R = VVD(n+1, VD(n+1, -1));  
		P = VD(n); 
		for(int i = 0; i < n; ++i) cin >> P[i]; 
		
		cout << f(0, 0) << endl; 
	}
	
	
	
}
