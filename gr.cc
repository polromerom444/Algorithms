#include <iostream>
#include <vector>
#include <queue>
using namespace std; 

using P = pair<int, int>; 
using VP = vector<P>; 
using VVP = vector<VP>; 
using VI = vector<int>; 
using VVI = vector<VI>; 

int n; 
VP V; 
int tf; 
VVI R; 


int f(int i, int tres) {
	
	cout << tres << endl; 
	tf = tres;
	if(i == n) return 0; 
	int& res = R[i][tres]; 
	if(res != -1) return res; 
	
	int t = V[i].first; 
	int k = V[i].second; 
	
	if(tres >= t) return res = max(k + f(i+1, tres - t), f(i+1, tres)); 	
	else return res = f(i+1, tres); 
}

int main () {
	int temps; 
	while(cin >> temps >> n) {
		tf = temps; 
		V = VP(); 
		for(int i = 0; i < n; ++i) {
			int s, k; 
			cin >> s >> k;
			if(k > s) V.push_back(P(s, k)); 	
		}
		n = V.size(); 
		R = VVI(n, VI(1e5, -1)); 
		cout << f(0, temps) + tf << endl; 
		cout << tf << endl; 	
	}	
}
