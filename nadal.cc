#include <iostream>
#include <vector>
using namespace std; 

using VI = vector<int>; 

int main () {
	int n; 
	int i = 1; 
	while(cin >> n) {
		cout << '#' << i << endl; 
		VI B(n); 
		cin >> B[0]; 
		for(int i = 1; i < n; ++i) {
			int x; 
			cin >> x;
			B[i] = B[i-1] + x; 
		}
		
		int q; 
		cin >> q; 
		while(q != 0) {
			int p, c; 
			cin >> p >> c;
			if(p <= c) cout << B[c-1] - (p-1 ? B[p-2] : 0) << endl; 
			else cout << B[p-1] - (c-1 ? B[c-2] : 0) << endl;
			--q;
		}
		++i; 
	}


}
	
	
