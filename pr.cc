#include <iostream>
#include <queue>
using namespace std; 



int main () {
	queue<int> Q; 
	queue<int> aux; 
	
	for(int i = 0; i < 3; ++i) {
		int s; cin >> s; 
		Q.push(s); 
	}
	aux = Q; 
	cout << aux.size() << endl; 
	
}
