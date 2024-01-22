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
const int MAX = 1e5 + 5;

struct fenwick {
    ll f1[MAX], f2[MAX];
    int n;
    
    fenwick (int n){
        this->n = n;
        memset(f1, 0, sizeof f1);
        memset(f2, 0, sizeof f2);
    }
    
    void update (ll f[], int x, ll val){
        for (; x <= n; x += (x & -x))
            f[x] += val;
    }

    void updateRange (int l, int r, ll val){
        update (f1, l, val);
        update (f1, r + 1, -val);
        update (f2, l, 1LL * (l - 1) * val);
        update (f2, r + 1, -1LL * (r + 1 - 1) * val);
    }

    ll get (ll f[], int x) {
        ll res = 0;
        for (; x; x -= x & -x)
            res += f[x];
        return res;
    }
    
    ll prefix (int i){
        return (1LL * i * get(f1, i) - get(f2, i));
    }
        
    ll getRange (int l, int r){
        return prefix(r) - prefix(l - 1);
    }
};

struct query {
    int l, r, d;
} q[MAX];

int n, m, k;
int a[MAX];
void run_case(){
    cin >> n >> m >> k;
    
    fenwick f(n);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++){
        cin >> q[i].l >> q[i].r >> q[i].d;
    }
    for (int i = 1; i <= k; i++){
        int x, y;
        cin >> x >> y;
    }
    
    
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    if (fopen(TASK ".inp", "r")) freopen(TASK ".inp", "r", stdin);
    
    int Test = 1;
    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}


