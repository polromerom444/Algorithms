#include <iostream>
#include <vector>
using namespace std;

using VI = vector<int>;

VI kmp(string s) {
	int n = s.size(); 
	VI P(n); 
	int j = -1; 
	for(int i = 0; i < n; ++i) {
		while(j >= 0 and s[j] != s[i]) j = (j? P[j-1] : -1); 
		P[i] = ++j; 
	}
	return P; 
}

int main() {
  string s;
  while(cin >> s) {
	VI P = kmp(s);
	int q = 0; 
	for (int x : P) cout << x <<  ' '; 
	cout << endl; 
}
}
