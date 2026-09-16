#include <iostream>
#include <vector>
using namespace std; 

using VI = vector<int>;
int n; 
 
const VI mon = {1, 2, 5, 10, 20, 50}; 
VI quant; 



void escriu() {
	bool primer = true; 
	for(int i = 5; i >= 0; --i) {
		for (int j = 0; j < quant[i]; ++j) {
			if(primer) {
				cout << mon[i];
				primer = false; 
			}
			else cout << ' ' << mon[i];  
		}
	}
	cout << endl; 	
	
}

	

void f(int i, int sum) {
	if (i == -1) {
		if (sum == n) return escriu();
		else return; 
	 }

	for(int j = n; j >= 0; --j) {
		if(sum + j*mon[i] <= n) {
			quant[i] = j;   
			f(i-1, sum + j*mon[i]);
		}
		
	}	
}
	
int main() {
	
	while (cin >> n) {
		quant = VI(6, 0);  
		f(5, 0);
		cout << endl; 
	} 
}
