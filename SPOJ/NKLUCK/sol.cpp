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
const int MAX = 1e6 + 5;



struct fenwick {
    ll f[MAX];
    int N;
    
    fenwick (int N){
        this->N = N;
        memset(f, 0, sizeof f);
    }

    ll get (int x){
        ll res = 0;
        for (; x; x -= x & -x)
            res += f[x];
        return res;
    }

    void update (int x, int val){
        for (; x <= N; x += x & -x)
            f[x] += val;
    }
};

int n, x;
int f[MAX], g[MAX], a[MAX];

ll solve(int k){
    vector <int> b;
    memset(f, 0, sizeof f);
    memset(g, 0, sizeof g);

    for (int i = 1; i <= n; i++){
        f[i] = f[i - 1] + (a[i] >= k);
        g[i] = 2 * f[i] - i;
        b.push_back(g[i]);
    }
    b.push_back(0);
    sort(all(b));
    b.erase(unique(b.begin(), b.end()), b.end());
    
    for (int i = 0; i <= n; i++)
        g[i] = (int) (lower_bound(all(b), g[i]) - b.begin()) + 1;
    
    fenwick BIT(b.size());
    ll res = 0LL;
    for (int i = 0; i <= n; ++i){
        res += BIT.get(g[i]);
        BIT.update(g[i], 1);
    }
    return res;
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    if (fopen(TASK ".inp", "r")) freopen(TASK ".inp", "r", stdin);
    
    int Test = 1;
    //cin >> Test;
    FOR(i, 1, Test){
        cin >> n >> x;
        for (int i = 1; i <= n; i++) cin >> a[i];
        ll res = solve(x);
        debug(res);
        res -= solve(x + 1);
        double W = (double) n * (n + 1) / 2.00;
        W = 1.00 * res / W;
        cout << fixed << setprecision(6) << W << "\n";
    }
}

