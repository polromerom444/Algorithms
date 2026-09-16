#include <iostream>
#include <vector>
using namespace std;


using VI = vector<int>;
using VB = vector<bool>;


int obj, n;
VI num;
VB triat;


void escriu() {
  bool primer = true;
  cout << '{';
  for (int i = 0; i < n; ++i)
    if (triat[i]) {
      if (primer) primer = false;
      else cout << ',';
      cout << num[i];
    }
  cout << '}' << endl;
}


void f(int i, int suma, int tot) {
	if (tot < obj - suma) return;
    if (suma > obj) return;  

    if (i == n) {
    if (suma == obj) escriu();
    return;
    }

    triat[i] = false;
    f(i + 1, suma, tot - num[i]);
    triat[i] = true;
    f(i + 1, suma + num[i], tot - num[i]);
  
}


int main() {
    int tot = 0; 
    cin >> obj >> n;
    num = VI(n);
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
        tot += num[i]; 
    }
    triat = VB(n);
    f(0, 0, tot);
    
}
