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
const int MAX = 3e5 + 5;

struct FenwickTree {
    int *f;
    int n;
    FenwickTree (int N) {
        f = new int[N + 1];
        this->n = N;
        for (int i = 0; i <= N; i++) f[i] = 0;
    }

    int get (int x) {
        int res = 0;
        for (; x; x -= x & -x)
            res ^= f[x];
        return res;
    }

    int query (int l, int r) {
        return (get(r) ^ get(l - 1)); 
    }
    void update (int x, int val) {
        for (; x <= n; x += x & -x)
            f[x] ^= val;
    }

};
int n, q;
struct Query {
    int l, r, id;
} query[MAX];
int a[MAX], res[MAX];
void run_case(){
    cin >> n >> q;
    FenwickTree bit(n);
    map <int, int> pos;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= q; i++) {
        int l, r; 
        cin >> l >> r;
        query[i] = {l, r, i};
    }
    sort(query + 1, query + 1 + q, [] (const Query x, const Query y) {
        return (x.r < y.r);
    });

    for (int i = 1, j = 1; i <= q; i++) {
        auto [l, r, id] = query[i];
        debug(l, r, id);
        for (; j <= r; j++) {
            if (pos[a[j]])
                bit.update(pos[a[j]], a[j]);
            pos[a[j]] = j;
            bit.update(pos[a[j]], a[j]);
        }
        res[id] = bit.query(l, r);
    }
    for (int i = 1; i <= q; i++) cout << res[i] << " \n"[i == q];
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

