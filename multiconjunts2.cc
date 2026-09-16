#include <iostream>
#include <vector>
using namespace std; 

using VI = vector<int>;

int n, x, y; 
VI V; 

void escriu() {
  bool primer = true;
  cout << '{';
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < V[i]; ++j) {
      if (primer) primer = false;
      else cout << ',';
      cout << i + 1;
    }
  cout << '}' << endl;
}


void f(int i) {
	if (i == n) return escriu(); 
	
	for (int j = x; j <= y; ++j) {
		V[i] = j;
		f(i+1);
	}
}


int main () {
	cin >> n >> x >> y;
	
	V = VI(n);
	f(0);
}

	
	 
	
