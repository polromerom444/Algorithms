#include <iostream>
#include <vector>
using namespace std; 

using VC = vector<char>;
using VI = vector<int>; 
using VVI = vector<VI>;  
int n; 
VI C; 
VVI R; 
string w1, w2; 

int min(int a, int b) {
	if(a < b) return a; 
	return b; 
}

// retorna el cost minim de fer w1[0....i-1] i w2[o.....j-1] iguals
int f(int i, int j) {
	int& res = R[i][j];
	if(res != -1) return res; 
	if(i == 0) {
		int r = 0; 
		for(int l = 0; l < j; ++l) r += C[int(w2[l]-'a')];
		return res = r; 
	} 
	if(j == 0) {
		int r = 0; 
		for(int l = 0; l < i; ++l) r += C[int(w1[l]-'a')];
		return res = r; 
	} 	
	
	if(w1[i-1] == w2[j-1]) return res = f(i-1, j-1); 
	return res = min(C[int(w1[i-1]-'a')] + f(i-1, j), C[int(w2[j-1]-'a')] + f(i, j-1));
}


int main () {
    while (cin >> n) { 
		C = VI(n); 
		for(int i = 0; i < n; ++i) cin >> C[i]; 
		cin >> w1 >> w2; 	
		int s1 = w1.size(); 
		int s2 = w2.size();
		R = VVI(s1+1, VI(s2+1, -1));  
		cout << f(s1, s2) << endl; 
	}
}
