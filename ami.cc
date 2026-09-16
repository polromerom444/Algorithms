#include <iostream>
#include <vector>
using namespace std; 

using VI = vector<int>; 



int main () {
	int n, q; 
	while(cin >> n >> q) {
		VI R(n+1); 
		for(int i = 0; i < n+1; ++i) R[i] = i;  
		while(q--) {
			char c; 
			cin >> c; 
			if(c == 'a') {
				int x, y; 
				cin >> x >> y; 
				int rx = R[x]; 
				int ry = R[y]; 
				if(rx != ry) {
					R[y] = rx; 
					for(int i = 0; i < n+1; ++i) {
						if(R[i] == ry) R[i] = rx; 
					}
				}
			}
			else {
				int x; 
				cin >> x; 
				int rx = R[x];
				int count = 0;  
				for(int i = 0; i < n+1; ++i) {
					if(R[i] == rx) ++count; 
				}
				cout << count << endl; 		
					
			}			
		}
		cout << "----------" << endl; 
	}
}
