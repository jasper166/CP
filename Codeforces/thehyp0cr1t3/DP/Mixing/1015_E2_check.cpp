#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

const int dx[] = {1, 0, -1,  0};
const int dy[] = {0, 1,  0, -1};
const int N = 1001;

int n, m;
vector<string> f;
int d[N][N][4];
int r[N][N], a[N][N], b[N][N];

int getd(int i, int j, int k) {
    int dxk = dx[k];
    int dyk = dy[k];
    int result = 0;
    while (i >= 0 && i < n && j >= 0 && j < m && f[i][j] == '*')
        result++, i += dxk, j += dyk;
    return result;
}

int main() {
    cin >> n >> m;
    f = vector<string>(n);
    forn(i, n)
        cin >> f[i];
    
    memset(d, -1, sizeof(d));
    int result = 0;
    for (int i = 1; i + 1 < n; i++)
        for (int j = 1; j + 1 < m; j++)
            if (f[i][j] == '*') {
                bool around = true;
                forn(k, 4)
                    around = around && (f[i + dx[k]][j + dy[k]] == '*');
                if (around) {
                    r[i][j] = INT_MAX;
                    forn(k, 4)
                        r[i][j] = min(r[i][j], getd(i, j, k) - 1);
                    result++;
                    a[i][j - r[i][j]] = max(a[i][j - r[i][j]], 2 * r[i][j] + 1);
                    b[i - r[i][j]][j] = max(b[i - r[i][j]][j], 2 * r[i][j] + 1);
                }
            }

    vector<string> g(n, string(m, '.'));
    forn(i, n) {
        int v = 0;
        forn(j, m) {
            v = max(v - 1, a[i][j]);
            if (v > 0)
                g[i][j] = '*';
        }
    }
    forn(j, m) {
        int v = 0;
        forn(i, n) {
            v = max(v - 1, b[i][j]);
            if (v > 0)
                g[i][j] = '*';
        }
    }
    
    if (f == g) {
        cout << result << endl;
        forn(i, n)
            forn(j, m)
                if (r[i][j] > 0)
                    cout << i + 1 << " " << j + 1 << " " << r[i][j] << endl;
    } else
        cout << -1 << endl;
}