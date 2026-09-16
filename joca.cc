#include <iostream>
#include <sstream>
using namespace std;





int main () {
	string s; 
	while(getline(cin,s)) {
		int n, m; 
		stringstream ss(s); 
		ss >> n >> m; 
		if(n != m) cout << "Bob" << endl; 
		else cout << "Alice" << endl; 
	}
}
