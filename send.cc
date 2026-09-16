#include <iostream>
#include <vector>
#include <string>
using namespace std; 

using VS = vector<string>; 
using VC = vector<char>; 
using VI = vector<int>; 

VS S; 
VC L; 
VI V; 
int n,l; 
 

bool esta(char c) {
	int lon = L.size(); 
	for(int i = 0; i < lon; ++i) {
		if(c == L[i]) return true; 
	}
	return false; 
}

void comprova() {
	int res = 0; 
	for(int k = 0; k < n - 1; ++k) {
		string s = S[k]; 
		int p = s.size(); 
		int a; 
		for(int j = 0; j < p; ++j) {
			char c = s[j]; 
			for(int i = 0; i < l; ++i) {
				if(L[i] == c) a = 10*a + V[i]; 
			}
		}
		res += a; 	
	}
	int res2 = 0; 
	string t = S[n-1]; 
	int q = t.size(); 
	for(int j = 0; j < q; ++j) {
		char c = t[j]; 
		for(int i = 0; i < l; ++i) {
			if(L[i] == c) res2 = 10*res2 + V[i]; 
		}
	}
	if(res == res2) {
		for(int i = 0; i < l; ++i) cout << V[i] << ' '; 
		cout << endl;
		cout << "-----------" << endl; 
		for(int k = 0; k < n-1; ++k) {
			if(k != 0) cout << " + "; 
			string s = S[k]; 
			int p = s.size(); 
			for(int j = 0; j < p; ++j) {
				char c = s[j]; 
				for(int i = 0; i < l; ++i) {
					if(L[i] == c) cout << V[i]; 
				}
			}	
		}
		cout << " = "; 
		string t = S[n-1]; 
		int q = t.size(); 
		for(int j = 0; j < q; ++j) {
			char c = t[j]; 
			for(int i = 0; i < l; ++i) {
				if(L[i] == c) cout << V[i]; 
			}
		}
		cout << "-----------" << endl; 
	}
	cout << res << ' ' << res2 << endl; 
}

void f(int i) {
	if(i == l) return comprova(); 
	
	for(int j = 0; j < 10; ++j) {
		V[i] = j; 
		f(i+1); 
	}
}

int main () {
	cin >> n; 
	S = VS(n);
	L = VC();  
	for(int i = 0; i < n; ++i) {
		string s; 
		cin >> s; 
		for(char c : s) if(not esta(c)) L.push_back(c); 
		S[i] = s; 
	}
	l = L.size();
	V = VI(l); 
	f(0);  
}
