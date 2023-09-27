#include "bits/stdc++.h"

using namespace std;

#define el "\n"
#define LL long long
#define name "ETOHARI"
#define hacker "ETOHARI"
#define fi first
#define se second
#define bit(a,b) ((a >> b)&1)
#define countBit(a) __builtin_popcount(a)
#define sum(l,r,val) accumulate(l,r,val)
#define flush cout.flush()

const int MAXN = 1e3 + 10;
const int MAXM = 5e3 + 10;
const int MOD  = 1e9 + 7;
const int INF = 1e9 + 7;

int n, r, c, a[MAXN][MAXN], check[MAXN][MAXN], res = -INF;
int dx[8] = { -2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = { -1, 1, 2, -2, -2, 2, -1, 1};
void dfs(int i, int j, int val) {
    check[i][j] = true;
    res = max(res, val);
    for (int k = 0; k < 8; k++) {
        int i1 = i + dx[k], j1 = j + dy[k];
        if (i1 >= 1 && j1 >= 1 && i1 <= n && j1 <= n && !check[i1][j1])
            dfs(i1, j1, val + a[i1][j1]);
    }
    check[i][j] = false;
}
int main() {
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> r >> c;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    dfs(r, c, a[r][c]);
    cout << res;
    return 0;
}