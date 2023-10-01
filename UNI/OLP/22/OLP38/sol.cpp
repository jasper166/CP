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

#ifdef LOCAL
#include "debug.h"
#define TASK "1311D"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 5e5 + 5;

int n, q;

struct query{
    int i, j, k, op, id;
};

query a[MAX];
int ans[MAX];

struct fenwick{
    int f[MAX];
    fenwick(){
        memset(f, 0, sizeof(f));              
    };
    void update(int x, int val){
        for (; x <= n; x += (x & (-x)))
            f[x] += val;
    }
    int get(int x){
        int ans = 0;
        for (; x; x -= (x & (-x)))
            ans += f[x];
        return ans;
    }
};

fenwick bit;

void run_case(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i].k;
        a[i].i = a[i].j = i;
        a[i].op = 0;
    }
    cin >> q;
    for (int i = n + 1; i <= n + q; i++){
        cin >> a[i].i >> a[i].j >> a[i].k;
        a[i].id = i - n;
        a[i].op = 1;
    }

    sort(a + 1, a + 1 + n + q, [](const query x, const query y){
        if (x.k == y.k)
            return x.op > y.op;
        return x.k > y.k;
            });
    for (int i = 1; i <= n + q; i++){
        if (a[i].op == 0)
            bit.update(a[i].i, 1);
        else 
            ans[a[i].id] = bit.get(a[i].j) - bit.get(a[i].i - 1);
    }
    for (int i = 1; i <= q; i++)
        cout << ans[i] << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    if (fopen(TASK ".inp", "r"))
        freopen(TASK ".inp", "r", stdin);
    
    int Test = 1;
//    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}

