#include <iostream>
#include <vector>
#include <queue>
using namespace std; 

using VI = vector<int>; 
using VVI = vector<VI>; 
using VC = vector<char>; 
using VVC = vector<VC>; 
using P = pair<int,int>; 
using PP = pair<double, P>; 

int main () {
	priority_queue<PP> Q; 
	int t, n; 
	cin >> t >> n; 
	while(n--) {
		int s, k; 
		cin >> s >> k; 
		double g = double(k)/double(s); 
		PP p = PP(g, P(s, k));
		Q.push(p);  
	}
 
	while(not Q.empty()) {
		PP q = Q.top(); Q.pop(); 
		cout << q.first << ' ' << q.second.first << ' ' << q.second.second << endl;
	}
}
	
