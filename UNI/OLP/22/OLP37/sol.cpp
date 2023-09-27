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
#define TASK "OLP37"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int n;
int a[MAX], b[MAX];

struct fenwick{
    int f[MAX];
    fenwick() = default;
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

void run_case(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; i++)
        a[i] = lower_bound(b + 1, b + 1 + n, a[i]) - b;
    // FOR(i, 1, n) cout << a[i] << "\n";
    vector <int> L(n + 1), R(n + 1);    
    fenwick bit;
    
    memset(bit.f, 0, sizeof(bit.f));
    for (int i = n; i >= 1; i--){
        R[i] = bit.get(a[i] - 1);
        bit.update(a[i], 1);
    }
    memset(bit.f, 0, sizeof(bit.f));
    for (int i = 1; i <= n; i++){
        L[i] = i - bit.get(a[i]) - 1;
        bit.update(a[i], 1);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        ans += 1LL * L[i] * R[i];
    cout << ans << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    if (fopen(TASK ".inp", "r"))
        freopen(TASK ".inp", "r", stdin);
    
    int Test = 1;
    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}

