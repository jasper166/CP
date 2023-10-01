#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;
using pii = pair < int, int >;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 5e4 + 5;

int n;
int dep[45 * MAX];
ll f[45 * MAX];
int d[45 * MAX];
int child[45 * MAX][26];
int cnt = 0;
void add(string s) {
    int u = 0;
    for (auto &c : s) {
        int nxt = c - 'a';
        if (child[u][nxt] == 0) {
            child[u][nxt] = ++cnt; 
            dep[cnt] = dep[u] + 1;
        }
        u = child[u][nxt];
    }
    // a string exists at u, leaf node;
    d[u] = 1;
}

void run_case() {
    cin >> n;
    for (int _ = 1; _ <= n; _++) {
        string s; cin >> s;
        add(s);
    }
    debug(cnt);
    for (int i = cnt; i >= 0; --i) {
        f[i] = 1ll << (40 - dep[i]);
        if (d[i]) continue;

        ll sum = 0;
        for (int j = 0; j < 26; ++j) {
            if (child[i][j])
                sum += f[child[i][j]];
        }
        if (i == 0) {
            f[i] = sum;
            continue;
        }

        f[i] = min(f[i], sum);
    }
    cout << f[0] << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}


