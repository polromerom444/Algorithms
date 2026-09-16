#include <iostream>
#include <vector>
using namespace std; 

using VI = vector<int>; 
using VVI = vector<VI>; 

VVI M; 
string s, t, u; 
int lt, ls;

const int N = 100000007; 

int f(int i, int j) {
	//cout << i << ' ' << j << endl; 
	int& res = M[i][j]; 
	if(i == 0) {
		for(int k = 0; k < j; ++k) {
			if(s[k] != u[k]) return res = 0; 
			//cout << s[k] << ' ' << u[k] << endl; 
		}
		return res = 1; 
	}
	if(j == 0) {
		for(int k = 0; k < i; ++k) {
			if(t[k] != u[k]) return res = 0;
			//cout << t[k] << ' ' << u[k] << endl; 
		}
		return res = 1; 
	}

	if(res != -1) return res; 
	
	res = 0; 
	if(j > 0 and s[j-1] == u[i+j-1]) res = (res + f(i, j-1))%N; 
	if(i > 0 and t[i-1] == u[i+j-1]) res = (res + f(i-1,j))%N; 
	return res; 
	
}




int main () {
	while(cin >> s >> t >> u) {
		lt = t.size(); ls = s.size(); 
		M = VVI(lt+1, VI(ls+1, -1)); 
		cout << f(lt, ls) << endl; 
		/*
		for(int i = 0; i < lt; ++i) {
			for(int j = 0; j < ls; ++j) {
				cout << M[i][j] << ' ';
			}
			cout << endl; 
		}
		*/
	} 
}
