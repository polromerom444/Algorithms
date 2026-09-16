#include <iostream>
#include <sstream>
using namespace std; 

const double t = 18.0/37.0; 

double prob(int q, int d) {
	double p = 1.00000; 
	while(q < d) {
		p *= t;
		if(p == 0) return p; 
		q *= 2; 
		
	}
	return p; 
}

int main () {
	cout.setf(ios::fixed);
    cout.precision(5);
	string s; 
	while(getline(cin, s)) {
		stringstream ss(s); 
		int n, m; 
		ss >> n >> m; 
		double probab = prob(n, m); 
		cout << probab << endl;
	}
}
