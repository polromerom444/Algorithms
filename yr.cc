#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
vector<string> t;
string s;

// Extends all paths from (i, j) to (n-1, m-1) satisfying the constraints.
// x == no. of obstacles so far *not counting* the possible one at (i, j).
void gen(int i, int j, int x)
{
    if (i >= n or j >= m)
        return;
    int y = x + (t[i][j] == 'X');
    if (y > k)
        return;
    // From (i, j) we need n - i - 1 Ds and m - j - 1 Rs to reach (n-1, m-1).
    if (y + n - i - 1 + m - j - 1 < k)
        return;
    if (i == n - 1 and j == m - 1)
        cout << s << endl;
    else {
        // From (0, 0) to (i, j) we already did i Ds and j Rs, that is, i+j steps.
        // If the first step is indexed by 0, the last one is indexed by i+j-1.
        // So the next to be defined has index i+j.
        s[i + j] = 'D';
        gen(i + 1, j, y);
        s[i + j] = 'R';
        gen(i, j + 1, y);
    }
}

int main()
{
    while (cin >> n >> m >> k) {
        t = vector<string>(n);
        for (auto& ti : t)
            cin >> ti;
        s = string(n + m - 2, ' ');
        gen(0, 0, 0);
        cout << string(10, '-') << endl;
    }
}
