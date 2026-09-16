#include <iostream>
#include <vector>
using namespace std;


using VI = vector<int>;


VI V;
string s; 

//nombre de seqs acabades en V[i]
int f(int i) {
	int& res = V[i];
	if(i == 0) return res = 0; 
	if (res != -1) return res;
	res = 0; 
	for (int j = 0; j < i; ++j){
		if (s[j] < s[i]) res += f(j) + 1;
	}
	return res; 
}


int main() {
  while(cin >> s) {
	  int n = s.size(); 
	  V = VI(n, -1);
	  int res = 0; 
	  for(int i = 1; i < n; ++i) res+= f(i);
	  cout << res << endl;
  }
}
