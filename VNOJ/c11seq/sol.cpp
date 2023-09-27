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

struct FenwickTree {
    ll f[MAX];
    int N;

    FenwickTree (int N) {
        this->N = N;
        memset(f, 0, sizeof f);
    }

    ll get(int x){
        ll res = 0LL;
        for (; x; x -= x & -x)
            res += f[x];
        return res;
    }

    void update(int x, ll val){
        for (; x <= N; x += x & -x)
            f[x] += val;
    }
};

int n, l, r;
ll f[MAX];
vector <ll> b;

int pos (ll val, vector <ll> &a){
    int p = (int) (upper_bound(all(a), val) - a.begin());
    return p;
}

void run_case(){
    cin >> n >> l >> r;
    f[0] = 0LL;
    b.push_back(0LL);
    for (int i = 1; i <= n; i++){
        int x; cin >> x;
        f[i] = f[i - 1] + 1LL * x;
        b.push_back(f[i]);
    }    
    sort(all(b));
    b.erase(unique(b.begin(), b.end()), b.end());
    FenwickTree BIT(b.size());
    ll res = 0;
    int x = pos(f[0], b);
    BIT.update(x, 1);
    for (int i = 1; i <= n; i++){
        int x = pos(f[i] - l, b);
        res += BIT.get(x);
        x = pos(f[i] - r - 1, b);
        res -= BIT.get(x);
        x = pos(f[i], b);
        BIT.update(x, 1);
    }
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

