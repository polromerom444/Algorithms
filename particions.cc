#include <iostream>
#include <vector>
using namespace std; 

using VI = vector<int>;
using VS = vector<string>;  

VI V; 
VS S; 
int n, p; 

void escriu() {
	for(int j = 0; j < p; ++j) {
		cout << "subconjunt " << j+1 << ": {";
		bool primer = true; 
		for(int i = 0; i < n; ++i) {
			if(j == V[i] and primer) {
				cout << S[i];
				primer = false; 
			} 
			else if (j == V[i]) cout << ',' << S[i]; 
		}
		cout << '}' << endl; 
	}
	cout << endl; 

}


void f(int i) {
	if(i == n) return escriu(); 
	
	for (int k = 0; k < p; ++k) { 
		V[i] = k; 
		f(i + 1);
	}
}
	

int main () {
	cin >> n; 
	V = VI(n);
	S = VS(n);
	for (int j = 0; j < n; ++j) {
		cin >> S[j]; 
	} 
	cin >> p;
	f(0); 	
}
