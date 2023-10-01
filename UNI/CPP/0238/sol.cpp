#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using pii = pair < int, int >;
using pll = pair < ll, ll >;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) x.begin(), x.end()

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#define debugArr(...) 42
#endif

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX =  25;

int n, m;
char a[MAX][MAX], ans[MAX][MAX];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void dfs(int x, int y){
    if (x > n || x < 1 || y > m || y < 1) return;
    if (a[x][y] != '?') return;
    a[x][y] = 'O';
    REP(i, 4)
        dfs(x + dx[i], y + dy[i]);
}

void run_case(){
    cin >> n >> m;
    FOR(i, 1, n) FOR(j, 1, m) cin >> a[i][j];


    FOR(i, 1, n)
        FOR(j, 1, m)
            if (a[i][j] == 'O') a[i][j] = '?';
    FOR(i, 1, n)
        if (a[i][1] == '?') dfs(i, 1);
    FOR(j, 1, m)
        if (a[n][j] == '?') dfs(n, j);
    FOR(i, 1, n)
        if (a[i][m] == '?') dfs(i, m);
    FOR(j, 1, m)
        if (a[1][j] == '?') dfs(1, j);

    FOR(i, 1, n) FOR(j, 1, m){
        if (a[i][j] == '?') a[i][j] = 'X';
        cout << a[i][j] << " \n"[j == m];
    }
    
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}
// Codename : Jasper the Otter



