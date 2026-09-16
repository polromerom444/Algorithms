#include <iostream>
#include <vector>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
using VB = vector<bool>;
using VVB = vector<VB>;
using VVVB = vector<VVB>;


VVI S(9, VI(9));
VVB fila, colu;
VVVB quad;
bool existeix_solucio;

void escriu() {
	bool fet1 = false; 	
	bool fet2 = false;
	
	existeix_solucio = true; 

	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			
			if(i == 3 and not fet1) {
				for(int k = 0; k < 21; ++k) {
					if(k == 6 or k ==  14) cout << '+'; 
					else cout << '-'; 
				}
				fet1 = true;
				cout << endl;  
			}
			else if(i == 6 and not fet2) {
				for(int k = 0; k < 21; ++k) {
					if(k == 6 or k ==  14) cout << '+'; 
					else cout << '-'; 
				}
				fet2 = true;
				cout << endl;  
			}
			else if(j == 3 or j == 6) {
					cout << ' ' << '|'; 
				} 
			cout << (j ? " " : "") << S[i][j];
		}
		cout << endl;
	}
	cout << endl; 
}

void f(int i, int j) {
	if (i == 9) return escriu();

	if (j == 9) return f(i + 1, 0);

	if (S[i][j]) return f(i, j + 1);

	for (int x = 1; x <= 9; ++x) {
		if (not fila[i][x] and not colu[j][x] and not quad[i/3][j/3][x]) {
			fila[i][x] = colu[j][x] = quad[i/3][j/3][x] = true;
			S[i][j] = x;
			f(i, j + 1);
			S[i][j] = 0;
			fila[i][x] = colu[j][x] = quad[i/3][j/3][x] = false;
		}
	}
}


int main() {
	int t;
	cin >> t;

	while (t--) {
		existeix_solucio = false; 
		fila = colu = VVB(9, VB(10, false));
		quad = VVVB(3, VVB(3, VB(10, false)));

		bool fet1 = false; 	
		bool fet2 = false; 	

		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
					
				if(i == 3 and not fet1) {
					for(int k = 0; k < 21; ++k) {
						char g; 
						cin >> g;
					}
					fet1 = true; 
				}
				if(i == 6 and not fet2) {
					for(int k = 0; k < 21; ++k) {
						char g; 
						cin >> g; 
					}
					fet2 = true; 
				}
				else if(j == 3 or j == 6) {
					char g; 
					cin >> g; 
				} 
						
				char c;
				cin >> c;
				int x = c - '0';
				S[i][j] = x;
				fila[i][x] = colu[j][x] = quad[i/3][j/3][x] = true;
			}
		}
	    f(0, 0);
	    
	    if (not existeix_solucio) cout << "no solution" << endl; 
	    cout << "******************************" << endl; 
	}
}
                                      
