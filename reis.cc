#include <iostream>
#include <vector>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;

int n, r; 
VVI T; 

void escriu() {
	for (int i=0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if(T[i][j] == 1) cout << 'K'; 
			else cout << '.'; 
		}
		cout << endl; 
	}
	cout << "----------" << endl; 
}

bool amenaça(int i, int j) {
	if(j > 0) {if(T[i][j-1] == 1) return true;}
	if(j < n) {if(T[i][j+1] == 1) return true;}
	if(i > 0) {
		{if(T[i-1][j] == 1) return true;}
		if (j > 0) {if(T[i-1][j-1] == 1) return true;}
		if (j < n) {if(T[i-1][j+1] == 1) return true;}
	}
	if(i < n-1) {
		{if(T[i+1][j] == 1) return true;}
		if(j < n) {if(T[i+1][j+1] == 1) return true;}
		if(j > 0) {if(T[i+1][j-1] == 1) return true;}
	}
	return false; 
}


void f(int i, int j, int sum) {
	if(sum == r) return escriu();			
	else if(i == n) return; 
	
	if (((n*n) - (i*n + j)) + 1 < (r - sum)*2) return;
	
	if (j == n) return f(i+1, 0, sum);
	  
	if(sum < r and not amenaça(i, j)) {
		T[i][j] = 1;         
		f(i, j+1, sum+1);
		T[i][j] = 0; 
	}	
	T[i][j] = 0; 
	f(i, j+1, sum);
} 




int main () {
	cin >> n >> r;
	T = VVI(n, VI(n, 0));  
	f(0,0,0); 
}
	 
	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
