#include <vector>
#include <iostream>
using namespace std; 

using VI = vector<int>; 
using VB = vector<bool>; 
using VC = vector<char>; 

int n, v, x; 
VI par; 
VB vocal; 

void escriu() { 
	for (int i = 0; i < n; ++i) {
        char c = 'a'+ par[i];
		cout << c; 
	}
	cout << endl; 
}


void f(int i, int nvoc, int cons) {
	if (i == n and v == nvoc) return escriu();
	
	if(v - nvoc + 1 < n - v - cons) return; 
	if(v - nvoc + 2 < (n - i)/2) return; 
	if (v - nvoc > n - i) return; 

    for (int j = 0; j < x; ++j) {
		if(vocal[j] and nvoc < v) {
			par[i] = j;
			f(i+1, nvoc+1, cons); 
		}
		if(not vocal[j] and (i== 0 or vocal[par[i-1]])) {
			par[i] = j;
			f(i+1, nvoc, cons+1); 
		}
		
	}
	
}
	

int main () {
	cin >> n >> v >> x; 
    par = VI(n); 
    vocal = VB(x);  
    for(int i = 0; i < x; ++i) {
        if(i == 0 or i == 4 or i == 8 or i == 14 or i == 20) {
            vocal[i] = true; 
        }
    }
	f(0, 0, 0);
}
