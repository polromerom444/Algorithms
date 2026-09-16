#include <iostream>
#include <set>
using namespace std; 



int main () {
	set<string> S; 
	string p; 
	cin >> p; 
	if(p != "END") {
		S.insert(p); 
		auto it = S.begin(); 
		cout << *it << endl; 
		while(cin >> p and p != "END") {
			int n = S.size(); 
			S.insert(p); 
			if(p < *it and n%2 == 1) --it; 
			else if(p > *it and n%2 == 0) ++it; 
			cout << *it << endl; 
		}
	}
}
		
