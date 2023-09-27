#include "bits/stdc++.h"
// @Jasper


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
const int MAX = 505;
const int N = INF;
int n, m;
int d[MAX][MAX];
int adj[MAX][MAX];
void run_case(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            d[i][j] = N;
    for (int i = 0; i < n; i++)
        d[i][i] = 0;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &adj[i][0], &adj[i][1], &adj[i][2]);
        adj[i][0]--;
        adj[i][1]--;
        d[adj[i][0]][adj[i][1]] = min(1, d[adj[i][0]][adj[i][1]]);
        d[adj[i][1]][adj[i][0]] = min(1, d[adj[i][1]][adj[i][0]]);
    }
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    ll ans = INF;
    for (int i = 0; i < m; i++) {
        int v = adj[i][0], u = adj[i][1];
        ans = min(ans, (ll)adj[i][2] * (1 + d[v][0] + d[u][n - 1]));
        ans = min(ans, (ll)adj[i][2] * (1 + d[v][n - 1] + d[u][0]));
        for (int w = 0; w < n; w++)
            ans = min(ans, (ll)adj[i][2] * (d[w][0] + d[w][n - 1] + min(d[w][v], d[w][u]) + 2));
    }
    printf("%lld\n", ans);

}

signed main(){
    // cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
    // cin >> Test;
    scanf("%d", &Test);
    FOR(i, 1, Test){

        run_case();
    }
}

