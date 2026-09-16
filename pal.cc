#include <iostream>
#include <stack>
using namespace std; 

int main () {
	stack<int> pila1; 
	stack<int> pila2; 
	
	int x;
	cin >> x;  
	while(x != ' ') {
		pila1.push(x);
		cin >> x; 
	} 
	int n = pila1.size(); 

	for(int i = 0; i < n/2; ++i) {
		int a = pila1.top(); 
		pila1.pop(); 
		pila2.push(a); 	
	}

	if(n%2 == 1) pila1.pop(); 
	int p1, p2; 
	bool found = false;
 
	 
	while (not pila1.empty() and not found) {
		p1 = pila1.top(); 
		pila1.pop(); 
		p2 = pila2.top(); 
		pila2.pop(); 

		if(p1 != p2) {
			found = true; 
			cout << "NO es un palindrom." << endl; 
		}
	}
	if(not found) cout << "Es un palindrom." << endl; 
	
}

	
