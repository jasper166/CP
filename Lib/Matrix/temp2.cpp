#include "bits/stdc++.h"
// @Jasper
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair <int, int>;

#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define sz(x) (int) size
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#ifdef LOCAL
#include "algo/debug.h"
#define TASK "in2"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e2 + 5;

using Matrix = vector <vector <ll>>;
int n, m, k;
vector <int> adj[MAX];
int dist[MAX][MAX];
int dp[MAX][MAX];

Matrix Mmul(Matrix a, Matrix b){
    int N = a.size();
    int M = a[0].size();
    int P = b[0].size();
    assert(b.size() == a[0].size());

    Matrix ans(N, vector <ll> (P, 0));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < P; j++)
            for (int k = 0; k < M; k++){
                ans[i][j] += (a[i][k] * b[k][j]) % MOD;
                ans[i][j] %= MOD;
            }
    return ans;
}


Matrix Mpow(Matrix a, ll x){

    assert(a.size() == a[0].size());
    int N = a.size();
    Matrix ans (N, vector <ll> (N, 0));
    for (int i = 0; i < N; i++) ans[i][i] = 1;

    while (x){
        if (x & 1) ans = Mmul(ans, a);
        a = Mmul(a, a);
        x >>= 1;
    }
    return ans;
}



void run_case(){
    cin >> n >> m >> k;

    Matrix ans (n, vector <ll> (n, 0));
    for (int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        ans[u - 1][v - 1]++;
    }

    ans = Mpow(ans, k);
    int res = 0;
    for (int u = 0; u < n; u++)
        for (int v = 0; v < n; v++){
            res += ans[u][v];
            res %= MOD;
        }
    cout << res << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    if (fopen(TASK ".inp", "r")) freopen(TASK ".inp", "r", stdin);

    int Test = 1;
    //cin >> Test;
    for(int i = 1; i <= Test; i++){

        run_case();
    }
}

