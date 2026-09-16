#include <iostream>
#include <vector>
using namespace std; 

int main () {
	using VI = vector<int>;
	using VVI = vector<VI>; 
	
	VVI S(9, VI(9)); 	
	bool fet1 = false; 	
    bool fet2 = false; 	

	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			
				
			if(i == 3 and not fet1) {
				for(int k = 0; k < 21; ++k) {
					char g; 
					cin >> g;
				}
				fet1 = true; 
			}
			if(i == 6 and not fet2) {
				for(int k = 0; k < 21; ++k) {
					char g; 
					cin >> g; 
				}
				fet2 = true; 
			}
			else if(j == 3 or j == 6) {
				char g; 
				cin >> g; 
			} 
					
			char c;
			cin >> c;
			int x = c - '0';
			S[i][j] = x;
			
		}
		cout << endl; 

