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
 
const int INF = 2e9 + 5;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
const ll LINF = 1e18 + 5;
// #define int long long

int n, x, res = INF;
tuple < int, int, int > a[MAX];
vector < pair < int, int > > adj[MAX];

void run_case() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        auto& [l, r, c] = a[i];
        cin >> l >> r >> c;
        adj[r - l + 1].emplace_back(l, c);
    }

    for (int i = 1; i < MAX; i++) {
        sort(adj[i].begin(), adj[i].end(), [](pair < int, int > X, pair < int, int > Y){
            return (X.fi < Y.fi || (X.fi == Y.fi && X.se > Y.se));
        });

        for (int j = (int) adj[i].size() - 2; j >= 0; j--)
            adj[i][j].se = min(adj[i][j + 1].se, adj[i][j].se);
    }
    for(int i = 1; i <= n; i++){
        auto &[l, r, c] = a[i];         
        if(x <= (r - l + 1)) continue;
        auto p = upper_bound(adj[x - r + l - 1].begin(), adj[x - r + l - 1].end(), make_pair(r, INF));
        if(p == adj[x - r + l - 1].end())continue;
        res = min(res, c + (*p).se);
    }

    cout << (res == INF ? -1 : res);
}
signed main(){
    cin.tie(0) -> sync_with_stdio(0);
 
    int Test = 1;
   // cin >> Test;
    FOR(i, 1, Test){
 
        run_case();
    }
}
// Codename : Jasper the Otter
 
