#include <iostream>
#include <vector>
using namespace std; 

using VI = vector<int>; 

VI V, E, salvat; 
int g, n; 

int compta() {
	int suma = 0; 
	for(int i = 0; i < n; ++i) {
		if(V[i]) {
			if(salvat[i] == 0 suma += V[i] + (V[i-1]+V[i+1]
			
	
}

void f(int i) {
	if (i == n) compta(); 



int main () {
	cin >> g >> n; 
	for(int i = 0; i < n; ++i) cin >> E[i]; 
	
	f(0); 
}
	
	
	
	
}
