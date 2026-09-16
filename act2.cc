#include <iostream>
#include <vector>
using namespace std; 


using VI = vector<int>;

const VI mon = {1, 2, 5, 10, 20, 50}; 
VI quant; 


int main() {
	int sum = 0; 
	for (int i = 0; i < 6; ++i) {
		sum += mon[i]; 
	}
	cout << sum << endl; 
}	
