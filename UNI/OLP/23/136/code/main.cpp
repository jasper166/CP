#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#ifdef JASPER2
#include "debug.h"
#else
#define debug(...) 166
#endif

using pii = pair < int, int >;
const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

using Matrix = vector <vector <int>>;

Matrix mMul(Matrix A, Matrix B) {
    int N = A.size();
    int M = A[0].size();
    int P = B[0].size();
    Matrix ans(N, vector <int> (P, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < P; ++j) {
            ll cur = 0;
            for (int k = 0; k < M; ++k) {
                cur += 1ll * A[i][k] * B[k][j];
                cur %= MOD;
            }
            ans[i][j] = cur;
        }
    }
    return ans;
}

Matrix mPow(Matrix A, int b) {
    int N = A.size();
    Matrix ans(N, vector <int> (N, 0));
    for (int i = 0; i < N; ++i) ans[i][i] = 1;
    while (b) {
        if (b & 1) ans = mMul(ans, A);
        A = mMul(A, A);
        b >>= 1;
    }
    return ans;
}

int n, m, k;

void run_case() {
    cin >> n >> m >> k;
    Matrix base(n, vector <int> (n, 0));
    Matrix A(1, vector <int> (n, 1));
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        base[u][v] = 1;
    }

    base = mPow(base, k);
    A = mMul(A, base);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += A[0][i];
        ans %= MOD;
    }
    cout << ans << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER2
        freopen("in2", "r", stdin);
    #endif

    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
