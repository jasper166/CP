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
#define TASK "61E"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

ll n, a[MAX], b[MAX];
ll BIT[MAX];
ll f[MAX], g[MAX];

void add(int x, int val){
    for (; x; x -= (x & -x))
        BIT[x] += val;
}

ll get(int x){
    ll sum = 0;
    for (; x < MAX; x += (x & -x))
        sum += BIT[x];
    return sum;
}


void run_case(){
    cin >> n;
    for (ll i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);
    for (ll i = 1; i <= n; i++) a[i] = lower_bound(b + 1, b + 1 + n, a[i]) - b;

    for (int i = 1; i <= n; i++){
        f[i] = get(a[i] + 1);
        add(a[i], 1);
    }
    

    memset(BIT, 0, sizeof(BIT));
    for (int i = 1; i <= n; i++){
        g[i] = get(a[i] + 1);
        add(a[i], f[i]);
    }
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
        ans += g[i];
    cout << ans << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
     /*   
    if (fopen(TASK ".inp", "r"))
        freopen(TASK ".inp", "r", stdin);
    cin >> Test;
    */
    FOR(i, 1, Test){

        run_case();
    }
}




