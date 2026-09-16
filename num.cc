#include <vector>
#include <iostream>
#include <algorithm>
using namespace std; 

using VI = vector<int>; 
using VB = vector<bool>;
using ll = long long;
 
ll n;
int l; 
bool existeix_solucio; 
VI V;
VB S;


void escriu() { 
	cout << n << " = "; 
	existeix_solucio = true; 
	for (int i = 0; i < l; ++i) {
		cout << V[i]; 
		if(i < l-1 and S[i]) cout << " + "; 
		
	}
	cout << endl; 
}


void f(int j, ll actual, ll sum) {
	if (j == l-1) {
		if(sum + actual*10 + V[j] == n) return escriu(); 
		else return; 
	}

	if(sum + actual*10 + V[j] <= n) {
		S[j] = true;
		f(j+1, 0, sum + actual*10 + V[j]);
	}
	S[j] = false; 
	f(j+1, actual*10 + V[j], sum);	
}  


int main () {
	while(cin >> n) { 
		existeix_solucio = false; 
		ll x; 
		cin >> x;
		ll orig = x; 
		ll i = 0;  
		V.clear();
		while(x != 0) {
			V.push_back(x%10); 
			x /= 10; 
			++i; 
		}
		reverse(V.begin(), V.end()); 
		l = i; 
		S = VB(l-1, false); 
		if (n > x) f(0, 0, 0); 
		if (not existeix_solucio) cout << "No solution for " << n << ' ' << orig << '.' << endl; 
	}
}
	
