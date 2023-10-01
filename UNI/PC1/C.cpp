#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using pii = pair < int, int >;
using pll = pair < ll, ll >;

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
#else
#define debug(...) 42
#define debugArr(...) 42
#endif

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
const ll LINF = 1e18 + 7;

ll a[MAX], n;
ll b[MAX];

ll getMax(multiset <ll> s){
    ll M1 = 1LL, M2 = 1LL;
    ll x[3], y[3];
    int cnt = 0;
    for (auto it = s.begin(); cnt != 2; cnt++, it++){
        x[cnt] = *it; 
    }
    auto it2 = s.end();
    x[2] = *(--it2);
    cnt = 0;
    for (; cnt != 3; it2--, cnt++){
        y[cnt] = *it2;
    }
    // REP(i, 3) cout << x[i] << " ";
    // cout << "\n";

    // REP(i, 3) cout << y[i] << " ";
    // cout << "\n";

    return max(x[0] * x[1] * y[0], y[0] * y[1] * y[2]);
}

void run_case(){
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) b[i] = -LINF; 
    b[1] = b[2] = 0LL;
    
    multiset <ll> s;
    s.insert(a[1]);
    s.insert(a[2]);

    FOR(i, 3, n){
        s.insert(a[i]);
        b[i] = max(b[i], getMax(s));
    }
    FOR(i, 1, n) cout << b[i] << " \n"[i == n];
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
    // cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}
// Codename : Jasper the Otter


