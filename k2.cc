#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Aresta {
  int x, y, c;
};

using VA = vector<Aresta>;
using VI = vector<int>;

int n, m;
VA V;
VI pare;

int repre(int x) {
  return (pare[x] == -1 ? x : pare[x] = repre(pare[x]));
}

bool abans(Aresta a, Aresta b) {
  return a.c < b.c; // cal que retorni false en cas d'igualtat
}

int kruskal() {
	int sum = 0; 
  sort(V.begin(), V.end(), abans);
  int q = n;
  pare = VI(n, -1);
  for (auto [x, y, c] : V) {
    int rx = repre(x);
    int ry = repre(y);
    if (rx != ry) {
//      pare[y] = x; pifia tipica
      pare[ry] = rx;
      sum += c; 
      
      if (--q == 1) return sum;
    }
  }
  return sum; 
}

int main() {
  cin >> n >> m;
  V = VA(m);
  for (auto& [x, y, c] : V) cin >> x >> y >> c;
  cout << kruskal() << endl; 
}
