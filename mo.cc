#include <iostream>
#include <vector>
using namespace std; 

using VD = vector<double>; 
using VVD = vector<VD>; 

VD P; 
VVD R; 
int d;

double prob(int n, int c, int x) {
	//cout << n << ' ' << k << endl; 
	if(n == -1) {
		if(k == 0) return 1; 
		else return 0; 
	}
	int dif; 
	if(c > x) dif = c - x; 
	else dif = x - c; 
	if(dif > d) return 0; 
	
	double& res = R[n][k]; 
	if(res != -1) return res; 
	
	
	double p = P[n]; 
	//cout << p << endl; 
	return res = p*prob(n-1, c+1, x) + (1-p)*prob(n-1, c, x+1);
	  
}

int main () {
	cout.setf(ios::fixed);
    cout.precision(4);
	int n; 
	while(cin >> d >> n) { 
		P = VD(n); 
		R = VVD(n, VD(1e5, -1));
		for(int i = 0; i < n; ++i) cin >> P[i]; 
		cout << prob(n-1, 0, 0) << endl; 
	}
	
}
