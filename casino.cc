#include <iostream>
#include <map>
using namespace std; 


int main () {
	map<string, int> M; 
	string s, t;  
	while(cin >> s >> t) {
		if(t == "enters") {
			auto it = M.find(s); 
			if(it != M.end()) cout << s << " is already in the casino" << endl; 
			else M[s] = 0; 
		}
		else if(t == "wins") {
			int n; 
			cin >> n; 
			auto it = M.find(s); 
			if(it == M.end()) cout << s << " is not in the casino" << endl;
			else M[s] += n; 	
		}
		else {
			auto it = M.find(s); 
			if(it == M.end()) cout << s << " is not in the casino" << endl;
			else {
				cout << s << " has won " << it->second << endl; 
				M.erase(s); 
			}	
		}	
	}
	cout << "----------" << endl; 
		for(auto it = M.begin(); it != M.end(); ++it) 
			cout << it->first << " is winning " << it->second << endl; 	
}
