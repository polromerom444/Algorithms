#include <iostream>
#include <vector>
#include <queue>
using namespace std; 


#include <iostream>
#include <queue>
using namespace std; 


using QS = queue<string>; 
using VQS = vector<QS>;


int main() {
    QS Q; 
    string s;
    VQS V(27);  
    while(cin >> s) Q.push(s);          
    int n = s.size(); 
    
    for(int i = n-1; i >= 0; --i) {
		string s; 
		while(not Q.empty()) {
			s = Q.front(); Q.pop(); 
			char c = s[i]; 
			V[int(c - 'a')].push(s); 	
		}
		for(int i = 0; i < 27; ++i) {
			string s; 
			while(not V[i].empty()) {
				s = V[i].front(); V[i].pop(); 
				Q.push(s); 
			}
		}					
	}
	bool primer = true; 
	while(not Q.empty()) {
		if(not primer) cout << ' '; 
		primer = false; 
		string s = Q.front(); Q.pop(); 
		cout << s; 
		}
		cout << endl;      
}
