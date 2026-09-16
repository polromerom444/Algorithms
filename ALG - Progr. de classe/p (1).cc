#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

const int UNDEF = -1;
const int oo = INT_MAX;

string w;
vector<vector<int>> c;

// Retorna el nombre mínim de girs per convertir w[i..j] en
// una parentització correcta.
int cost(int i, int j) {
  if (i > j) return 0;
  int& res = c[i][j];
  if (res != UNDEF) return res;
  res = +oo;
  for (int k = i+1; k <= j; k += 2) {
    res = min(res, (w[i] != '(') + (w[k] != ')') + cost(i+1, k-1) + cost(k+1, j));
  }
  return res;
}

int main() {
  while (cin >> w) {
    int n = w.size();
    c = vector<vector<int>>(n, vector<int>(n, UNDEF));
    cout << cost(0, n-1) << endl;
  }
}
