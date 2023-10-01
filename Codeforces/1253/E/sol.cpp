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

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

#define int long long
using pii = pair < int, int >;
const int INF = 1e9;
const int MOD = 998244353;
const int N = 1e6 + 5;

int fact[N], invs[N];

int Power (int A, int B) {
    ll res = 1;
    for (; B ; B >>= 1, A = (1LL * A * A) % MOD)
       if (B & 1)
        (res *= A) %= MOD;
    return (int) res;
}

int C(int N, int K) {
    if (K > N || N < 0 || K < 0)
        return 0;
    return (1LL * (1LL * fact[N] * invs[N - K]) % MOD * invs[K]) % MOD;
}
void prepare(int N) {

    fact[0] = 1;
    for (int i = 1 ; i <= N ; i ++)
        fact[i] = (1LL * fact[i - 1] * i) % MOD;

    invs[N] = Power(fact[N], MOD - 2);
    for (int i = N - 1 ; i >= 0 ; i --)
        invs[i] = (1LL * invs[i + 1] * (i + 1)) % MOD;
} 


int n;
string s;
void run_case() {
    cin >> s;
    int n = s.size();
    vector <pii> x;
    x.push_back({s[0], 1});

    FOR(i, 1, n - 1) {
        if (s[i] != x.back().fi) 
            x.push_back({s[i], 1});
        else 
            x.back().se++;
    }
    int t1 = 1, t2 = 1;
    int c = 0;
    for (auto [F, S] : x) {
        c += S - 1;
        t1 = (t1 * C(S, S - 1)) % MOD;
    }
    FOR(i, 1, c)
        t2 = (t2 * i) % MOD;
    int res1 = n - x.size();
    int res2 = (t1 * t2) % MOD;
    cout << res1 << " " << res2 << "\n";   
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    prepare(N - 1);
    int Test = 1;
    cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}


