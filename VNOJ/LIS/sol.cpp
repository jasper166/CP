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
const int MAX = 3e4 + 5;

struct fenwick {
    int n;
    int f[MAX];

    fenwick (int n){
        this->n = n;
        memset(f, 0, sizeof f);
    }

    int get(int x){
        int res = 0;
        for (; x; x -= x & -x)
            res = max(res, f[x]);
        return res;
    }
    void update (int x, int val){
        for (; x <= n; x += x & -x)
            f[x] = max(f[x], val);
    }
};

int a[MAX];
int n;

void run_case(){
    cin >> n;
    vector <int> b(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(all(b));
    for (int i = 1; i <= n; i++)
        a[i] = (int) (lower_bound(all(b), a[i]) - b.begin());

    fenwick BIT(n);
    int res = 1;
    for (int i = 1; i <= n; i++){
        int cur = BIT.get(a[i] - 1) + 1;
        res = max(res, cur);
        BIT.update(a[i], cur);
    }
    debugArr(BIT.f, 1, 5);
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

