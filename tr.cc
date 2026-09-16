#include <iostream>
#include <vector>
using namespace std; 

using VD = vector<double>;
using VVD = vector<VD>;  

int d, n; 
double p;  
VVD R; 


double f(int i, int c) {
	int dif = abs(c - (i-c)); 
	if(i == n and dif <= d) return 1; 
	double& res = R[i][c]; 
	if(res != -1) return res; 

	//cout << "cares: " << c << " i creus " << i - c << " dif " << dif << endl; 
	if(dif > d) return 0; 
	return res = p*f(i+1,c+1) + (1 - p)*f(i+1,c); 
	
}

int main () {
	cout.setf(ios::fixed);
    cout.precision(4); 
    
    while(cin >> p >> n >> d) {
		R = VVD(n+1, VD(n+1, -1));  
		cout << f(0, 0) << endl; 
	}
}
