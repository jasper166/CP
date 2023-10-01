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
#define TASK "QMAX"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

int n, u, q;
int st[4 * MAX], lazy[4 * MAX];

void update(int k, int l, int r, int L, int R, int val){
    if (l > r || R < l || L > r) 
        return;
    if (L <= l && r <= R){
        st[k] += val;
        lazy[k] += val;
        return;
    }
    int m = (l + r) / 2;
    update(k * 2, l, m, L, R, val);
    update(k * 2 + 1, m + 1, r, L, R, val);

    st[k] = max(st[k * 2], st[k * 2 + 1]) + lazy[k];
}

int get(int k, int l, int r, int L, int R){
    if (l > r || R < l || L > r)
        return -INF;
    if (L <= l && r <= R) 
        return st[k];
    int m = (l + r) / 2;
    return max(get(k * 2, l, m, L, R), get(k * 2 + 1, m + 1, r, L, R)) + lazy[k];
}

void run_case(){
    cin >> n >> u;
    for (int i = 1; i <= u; i++){
        int l, r, val;
        cin >> l >> r >> val;
        update(1, 1, n, l, r, val);
    }
    cin >> q;
    for (int i = 1; i <= q; i++){
        int l, r;
        cin >> l >> r;
        cout << get(1, 1, n, l, r) << "\n";
    }
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
/*
6 2
1 3 2
4 6 3
1
3 4

3
*/
