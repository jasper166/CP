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
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#ifdef LOCAL
#include "debug.h"
#define TASK "INP"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e3 + 5;

struct Matrix {
    vector <vector <int>> f;
    int n, m;
    Matrix (int N, int M) {
        f.assign(n + 1, vector <int> (m + 1, 0));
        n = N;
        m = M;
    }

    Matrix Multiply (Matrix a, Matrix b) {
        int n = a.n;
        int m = b.m;
        Matrix c(n, m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < n; k++) {
                   c.f[i][j] += (1LL * a.f[i][k] + b.f[k][j]) % MOD; 
                   c.f[i][j] %= MOD;
                }
            }
        }
        return c;
    }

    Matrix Power (Matrix a, int b) {
        int n = a.n;
        int m = a.m;
        Matrix res(n, m);
        assert (n == m);
        for (int i = 0; i < n; i++) a.f[i][i] = 1;

        while (b) {
            if (b & 1)
                res = Multiply(res, a);
            a = Multiply(a, a);
            b >>= 1;
        }
        return res;
    }
};

int fac[MAX], inv[MAX];

int Pow (int a, int b) {
    ll res = 1;
    while (b) {
        if (b & 1) 
            res = (1LL * res * a) % MOD;
        a = (1LL * a * a) % MOD;
        b >>= 1;
    }
    return (int) res % MOD;
}

void prepare (int N) {
    fac[0] = 1;
    for (int i = 1; i <= N; i++)
        fac[i] = (1LL * fac[i - 1] * i) % MOD;
    inv[N] = Pow(fac[N], MOD - 2);
    for (int i = N - 1; i >= 1; i--)
        inv[i] = (1LL * (inv[i + 1] * (i + 1))) % MOD;
}

int C (int n, int k) {
    return ((1LL * fac[n] * inv[n - k]) % MOD * inv[k]) % MOD;
}

int func (ll n, int k) {
    n %= MOD;

    vector <int> f(k + 2, 0);
    f[0] = n;
    f[1] = (1LL * n * (n + 1) * inv[2]);

    for (int i = 2; i <= k; i++) {
        int cur = Pow(n + 1, i + 1) - 1;
        for (int j = 0; j < i; j++) {
            cur -= (1LL * C(i + 1, j) * f[j]) % MOD; 
            while (cur < MOD) cur += MOD;
        }
        f[i] *= inv[i + 1];
        f[i] %= MOD;
    }
    return f[k];
}
    
void run_case(){
    ll n;
    int k;
    cin >> n >> k;
    cout << func(n, k) << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    if (fopen(TASK ".inp", "r")) freopen(TASK ".inp", "r", stdin);
    
    prepare(MAX - 1);
    int Test = 1;
    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}
