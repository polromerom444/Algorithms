#include <iostream>
#include <vector>
using namespace std; 

using VI = vector<int>;
int n, x, y, t;
 
VI V; 


void escriu() {
	if (t == 0) cout << "{}" << endl; 
	else {
		bool primer = true; 
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < V[i]; ++j) {
				if (primer) {
					cout << '{' << i + 1; 
					primer = false; 
				}
				else cout << ',' << i + 1;
		
			}
			
		}
		cout << '}' << endl;  
	}
}

int min(int x, int y) {
	if (x >= y) return x; 
	return y; 
}
	

void f(int i, int sum) {
	if (i == n) {
		if (sum == t) return escriu();
		else return;
	}
	
	if (t - sum > (n - i + 1)*y) return; 
	
	for (int j = x; j < min(y, t); ++j) {
		if (sum + j <= t) {
			V[i] = j;  
			f(i+1, sum + j);
		}
	}
}
	
int main() {
	cin >> n >> x >> y >> t;
	V = VI(n); 
	f(0, 0); 
}
	
	
	
