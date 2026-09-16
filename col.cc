#include <iostream>
#include <queue>
#include <sstream>
using namespace std; 






int main () {
	priority_queue<int> Q; 
	
	string s;
	while (getline(cin, s)) {
		stringstream ss(s); 
		char c; 
		bool error = false; 
		while(ss >> c and not error) {
			if(c == 'S') {
				int n; 
				ss >> n; 
				Q.push(n); 
			}
			else if(Q.empty()) {
				cout << "error!" << endl; 
				error = true; 
			}
			else if (c == 'A') {
				int m = Q.top();
				cout << m << endl; 	
			}
			else if (c == 'R') Q.pop(); 
			else if (c == 'I') {
				int x; 
				ss >> x; 
				int m = Q.top(); Q.pop(); 
				Q.push(m+x); 	
			}
			else {
				int x; 
				ss >> x; 
				int m = Q.top(); Q.pop(); 
				Q.push(m-x);
			}
		}
	}
}
