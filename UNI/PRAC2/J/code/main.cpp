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
const int MOD = 100;
const int MAX = 1e5 + 5;

using Matrix = vector <vector <int>>;

Matrix mMul(Matrix A, Matrix B) {
    int N = A.size();
    int M = A[0].size();
    int P = B[0].size();

    Matrix ans(N, vector <int>(P, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < P; ++j) {
            ll cur = 0;
            for (int k = 0; k < M; ++k) {
                cur += 1ll * A[i][k] * B[k][j] % MOD;
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

int n;
void run_case() {
    cin >> n;
    int pos = 0;
    for (int i = 0; i < 4; ++i) {
        int x; cin >> x;
        if (x)
            pos += (1 << i);
    }
    Matrix ans(1, vector <int> (16, 0));
    ans[0][0] = 6;
    for (int msk = 1; msk < 16; ++msk)
        if (msk == 1 || msk == 2 || msk == 4 || msk == 8)
            ans[0][msk] = 1;
    Matrix base(16, vector <int>(16, 0));
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            if (i == j) base[i][j] = 6;
            int x = (i ^ j);
            if (x == 1 || x == 2 || x == 4 || x == 8) base[i][j] = 1;
        }
    }
    debug(ans);
    ans = mMul(ans, mPow(base, n - 1));
    cout << ans[0][pos] << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER2
        freopen("in1", "r", stdin);
    #endif

    int Test = 1;
    cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
