#include "bits/stdc++.h"
// @Jasper
using namespace std;
using ll = long long;
using pii = pair < int, int >;

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
#define TASK "TSP_DP"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 16;

int c[MAX][MAX];
int n;

int f[1 << MAX | 1][MAX];

int func(int msk, int v){
    if (f[msk][v] != -1)
        return f[msk][v];
    if (msk == (1 << n) - 1)
        return c[v][0];
    int ans = INF;
    for (int u = 0; u < n; u++){
        if (msk & (1 << u)) continue;
        int nxt = msk | (1 << u);
        int newdist = c[v][u] + func(nxt, u);
        ans = min(ans, newdist);
    }
    return f[msk][v] = ans;
}

void run_case(){
    string s; cin >> s;
    int n = s.size();
    s = "%" + s;
    vector <int> f(n + 1);
    int res = 0;
    for (int i = 1; i <= n; i++) {
        f[i] = 1;
        for (int j = 1; j < i; j++)
            if (s[i] >= s[j])
                f[i] = max(f[i], f[j] + 1);
        res = max(res, f[i]);
    }
    cout << res << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    if (fopen(TASK ".inp", "r"))
        freopen(TASK ".inp", "r", stdin);
    
    int Test = 1;
    //cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}




