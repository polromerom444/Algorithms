#include <iostream>
#include <vector>
#include <queue>
using namespace std; 

using VI = vector<int>; 
using VVI = vector<VI>; 

VVI G; 
VI color; 
int count1, countv; 

bool bfs(int ini) {
    queue<int> Q; 
    Q.push(ini); 
    color[ini] = 0; 
    ++countv; 
    while(not Q.empty()) {
        int x = Q.front(); Q.pop(); 
        for(int y : G[x]) {
            if(color[y] == -1) {
                //cout << "visito " << x << " a " << y << endl; 
                color[y] = 1 - color[x]; 
                ++countv; 
                if(color[y] == 1) ++count1; 
                //cout << "pinto " << y << " de " << 1 - color[x] << endl; 
                Q.push(y); 
            }
            else if(color[y] == color[x]) return false; 
        }
    }
    return true; 
}

int main () {
    int n, m; 
    while(cin >> n >> m) {
        int x, y; 
        G = VVI(n); 
        color = VI(n, -1); 
        for(int i = 0; i < m; ++i) {
           cin >> x >> y; 
           G[x].push_back(y); 
           G[y].push_back(x); 
        }
        int i = 0; 
        bool trobat = false; 
        int res = 0; 
        while(i < n and not trobat) {
            if(color[i] == -1) {
				count1 = 0; 
				countv = 0; 
                //cout << "inicio vertex " << i << endl; 
                if(not bfs(i)) trobat = true;  
                //if(not trobat) cout << countv << ' ' << count1 << endl; 
                if(count1 > countv/2) res += count1; 
                else res+= countv - count1; 
            } 
            ++i;        
        }

        if(trobat) cout << "no" << endl; 
        else cout << "yes" << ' ' << res << endl; 
    }
}
