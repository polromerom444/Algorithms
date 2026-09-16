#include <iostream>
using namespace std; 



int main () {
	cout.setf(ios::fixed);
    cout.precision(4);
    
    double n;
    cin >> n;
    double m = n;   

	double p = 1;	
	while(n > 1) {
		p *= double(n-1)/double(n); 
		cout << "al moment" << p << endl; 	
		--n; 
	}
	cout << double(1.0/m) + p << endl; 
}

