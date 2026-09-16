#include <iostream>
#include <vector>
using namespace std; 

using VI = vector<int>; 
using VVI = vector<VI>; 

int coins, val; 

VI C = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29}; 
VI quant(10, 0); 
VVI R(21, VI(1e6+1, -1)); 

int factorial(int n) {
    if (n == 0) return 1; 
    return n*factorial(n - 1); 
}

int f(int c, int v) {
	if(v < 0) return 0; 

    int& res = R[c][v]; 
    if(res != -1) return res;  
    if(c == 1) {
        if(v == 2 or v == 3 or v == 5 or v == 7 or v == 11 or v == 13 or v == 17
           or v == 19  or v == 23 or v == 29) return res = 1;
        else return res = 0; 
    }

    res = 0; 
    for(int i = 0; i < 10; ++i) {
		for(int j = 0; j < i
		int a = f(c-1, v-C[i]); 
		cout << c << ' ' << v << ' ' << a << endl; 
        res += a; 
    }
    return res;  
}


int main () {
    int n; 
    cin >> n; 
    for(int k = 0; k < n; ++k) {
        cin >> coins >> val; 
        cout << f(coins, val) << endl; 
    }
}
