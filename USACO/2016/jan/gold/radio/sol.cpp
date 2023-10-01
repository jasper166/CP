#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second
#ifdef JASPER2
#include "debug.h"
#else
#define debug(...) 166
#endif

// #define int long long
using pii = pair < int, int >;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 1e3 + 5;

int dp[N][N];
// minimum energy at ith move of F and jth move of B
int n, m;
int fx, fy, bx, by;
string fp, bp;

map <char, pii> dir;
pii f[N], b[N];

int dist(int i, int j) {
    return ((f[i].fi - b[j].fi) * (f[i].fi - b[j].fi) 
        + (f[i].se - b[j].se) * (f[i].se - b[j].se));
}
void run_case() {
	cin >> n >> m;	
    cin >> fx >> fy >> bx >> by;
    cin >> fp >> bp;

    fp = "@" + fp;
    bp = "@" + bp;
    dir['N'] = {0, 1};
    dir['S'] = {0, -1};
    dir['W'] = {-1, 0};
    dir['E'] = {1, 0};

    f[0] = {fx, fy};
    for (int i = 1; i <= n; ++i) {
        char c = fp[i];
        f[i].fi = f[i - 1].fi + dir[c].fi;
        f[i].se = f[i - 1].se + dir[c].se;
        // cout << f[i].fi << " " << f[i].se << "\n";
    }

    b[0] = {bx, by};
    for (int i = 1; i <= m; ++i) {
        char c = bp[i];
        b[i].fi = b[i - 1].fi + dir[c].fi;
        b[i].se = b[i - 1].se + dir[c].se;
        // cout << b[i].fi << " " << b[i].se << "\n";
    }

    // cout << dist(1, 1) << "\n";
    for (int i = 0; i <= n + 5; ++i)
        fill(dp[i], dp[i] + m + 5, INF);

    dp[0][0] = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + dist(i + 1, j));
            dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + dist(i, j + 1));
            dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + dist(i + 1, j + 1));
        }
    }
    cout << dp[n][m] << "\n";
}

void setIO(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}


signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER2
        freopen("in1", "r", stdin);
    #endif

    setIO("radio");
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

