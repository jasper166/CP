#include "bits/stdc++.h"
// @Jasper
using namespace std;

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
#define int long long
using ll = long long;
using pii = pair < int, int >;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const ll LINF = 1e18 + 5;
const int INF = 0x3f3f3f3f;
//const int MOD = 1e9 + 7;
const int MAX = 3e6 + 5;

int n, MOD;
int fact[MAX], invs[MAX];
int f[12];

int Power (int A, int B) {
        int64_t res = 1;
        for (; B ; B >>= 1, A = (1LL * A * A) % MOD)
             if (B & 1)
                (res *= A) %= MOD;
        return (int) res;
}
 
int C (int N, int K) {
        if (K > N || N < 0 || K < 0)
                return 0;
        return (1LL * (1LL * fact[N] * invs[N - K]) % MOD * invs[K]) % MOD;
}
 
int P (int N, int K) {
        if (K > N)
                return 0;
        return (1LL * fact[N] * invs[N - K]) % MOD;
}
 
void prepare (int N) {
        fact[0] = 1;
        for (int i = 1 ; i <= N ; i ++)
                fact[i] = (1LL * fact[i - 1] * i) % MOD;
        invs[N] = Power(fact[N], MOD - 2);
        for (int i = N - 1 ; i >= 0 ; i --) {
                invs[i] = (1LL * invs[i + 1] * (i + 1)) % MOD;
        }
}

void run_case(){ 
    cin >> n >> MOD;

    prepare(MAX - 1);
    f[0] = 1;
    f[1] = ((2LL * fact[2 * n]) % MOD - fact[n] % MOD + MOD) % MOD; 
    f[2] = ((fact[2 * n] * C(2 * n, n) % MOD) * fact[n] % MOD) * 2 % MOD;
    f[3] = fact[3 * n];
    for (int i = 0; i <= n; i++)
        f[2] = (f[2] - (((((C(n, i) * C(n, n - i) % MOD) * C(2 * n - i, n) % MOD) * fact[n] % MOD) * fact[n] % MOD) * fact[n] % MOD) + MOD) % MOD;
        
        (f[3] -= f[2] + MOD) %= MOD;
        while (f[3] < MOD) f[3] += MOD;
        f[3] %= MOD;

        (f[2] -= f[1] + MOD) %= MOD;
        while (f[2] < MOD) f[2] += MOD;
        f[2] %= MOD;

        (f[1] -= f[0] + MOD) %= MOD;
        while (f[1] < MOD) f[1] += MOD;
        f[1] %= MOD;
    int res = 0;
    FOR(i, 1, 3){ 
        // cout << f[i] << "\n";
        res += (f[i] * i) % MOD;
        res %= MOD;
    }
//     debug(f[1], f[2], f[3]);
    cout << res << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    if (fopen(TASK ".inp", "r")) freopen(TASK ".inp", "r", stdin);

    int Test = 1;
    //cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}



