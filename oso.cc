#include <iostream>
#include <vector>
using namespace std; 

using VI = vector<int>; 
using VVI = vector<VI>; 
using VC = vector<char>; 
using VVC = vector<VC>; 

bool guanya() {
	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j) {
			if(T[i][j] == 'O') {
				if(T[i-1][j] == 'S' and T[i+1][j] == 'S') return true; 
				else if(T[i][j-1] == 'S' and T[i][j+1] == 'S') return true; 
			}	
		}
	}
	return false; 
}


int main() {
	cout.setf(ios::fixed);
    cout.precision(4);
	int k; 
	while(k--) {
		VVC T(3, VC(3)); 
		for(int i = 0; i < 3; ++i) {
			for(int j = 0; j < 3; ++j) cin >> T[i][j]; 
		}
		
		
		
	}
}
	
