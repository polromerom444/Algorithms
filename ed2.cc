#include <iostream>
#include <vector>
#include <cmath>
using namespace std; 

using VC = vector<char>;
using VI = vector<int>; 
using VD = vector<double>; 
using VVI = vector<VI>;  
int n, cmin; 
VD C; 
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
	if(i == 0 and j == 0) return res = 0; 
	
	if(w1[i-1] == w2[j-1]) return res = f(i-1, j-1); 
	if(i <= 0) return res = min(C[int(w2[j-1]-'a')] + f(i, j-1),
	                            ceil((cmin + C[int(w2[j-1]-'a')])/4) + f(i,j-1)); 
	if(j <= 0) return res = min(C[int(w1[i-1]-'a')] + f(i-1, j), 
	                            ceil((cmin + C[int(w1[i-1]-'a')])/4) + f(i-1, j)); 
	                 
	return res = min(min(C[int(w1[i-1]-'a')] + f(i-1, j), C[int(w2[j-1]-'a')] + f(i, j-1)), 
	             min(ceil((C[int(w1[i-1]-'a')] + C[int(w2[j-1]-'a')])/4) + f(i-1, j-1), 
	                 min(ceil((cmin + C[int(w1[i-1]-'a')])/4) + f(i-1, j), 
	                     ceil((cmin + C[int(w2[j-1]-'a')])/4) + f(i,j-1)))); 
} 


int main () {
    while (cin >> n) { 
		C = VD(n); 
		cmin = 10000; 
		for(int i = 0; i < n; ++i) {
			cin >> C[i]; 
			cmin = min(cmin, C[i]); 
		}
		cin >> w1 >> w2; 	
		int s1 = w1.size(); 
		int s2 = w2.size();
		R = VVI(s1+1, VI(s2+1, -1));  
		cout << f(s1, s2) << endl; 
		for(int i = 0; i < s1+1; ++i) {
			for(int j = 0; j < s2+1; ++j) cout << R[i][j] << ' '; 
			cout << endl; 
		}
	}
}


