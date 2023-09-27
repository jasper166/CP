#include "bits/stdc++.h"
// @Jasper
using namespace std;
using ll = long long;
using pii = pair < int, int >;

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
#else
#define debug(...) 166
#define debugArr(...) 166
#endif


const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e4 + 5;

ll C4(int n) {
    return (1ll * n * (n - 1) * (n - 2) * (n - 3) / 24);
}

int d[MAX];

void prepare() {
    for (int i = 0; i < MAX; i++) d[i] = i;
    for (int i = 2; i * i < MAX; i++) {
        if (d[i] == i)
            for (int j = 2 * i; j < MAX; j += i)
                d[j] = min(d[j], i);
    }
}


int n;
vector <int> primes;
int cnt[MAX], a[MAX], bit[MAX];

void run_case() {

    for (int i = 1; i <= n; i++) cin >> a[i];

    if (n < 4) {
        cout << "0\n";
        return;
    }
    memset(cnt, 0, sizeof cnt);
    memset(bit, 0, sizeof bit);
    int LIM = *max_element(a + 1, a + 1 + n);
    
    for (int i = 1; i <= n; i++) {
        int x = a[i];
        primes.clear();
        vector <bool> used(LIM, 0);
        while (x != 1) {
            if (!used[d[x]]) {
                primes.push_back(d[x]);
                used[d[x]] = 1;
            }
            x /= d[x];
        }
        // debug(primes);
        int k = primes.size();
        for (int msk = 1; msk < (1 << k); msk++) {
            int m = 1;
            for (int i = 0; i < k; i++)
                if (msk & (1 << i)) 
                    m *= primes[i];
            cnt[m]++; 
            bit[m] = __builtin_popcount(msk);
        }
    }

    // cnt[] : denote frequency of gcd of quadruple

    ll total = C4(n);
    ll exl = 0;
    for (int x = 2; x <= LIM; x++) {
        if (cnt[x] < 4)
            continue;
        if (bit[x] & 1)
            exl += C4(cnt[x]);
        else
            exl -= C4(cnt[x]);
    }
    ll ans = total - exl;
    cout << ans << "\n"; 
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    prepare();

    while (cin >> n) 
        run_case();
    // cin >> Test;
    // for (int test = 1; test <= Test; test++){

    //     run_case();
    // }
}

