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
const int MAX = 1e5 + 5;

int n, m;
int x[MAX], y[MAX], spec[10];

int getVal(int z){
    if (z == 0) return 0;
    if (z == 1) return spec[0];
    int id = upper_bound(y + 1, y + 1 + m, z) - y;
    int ans = spec[0] + spec[1];
    ans += m - id + 1;
    if (z == 2) ans -= spec[3] + spec[4];
    if (z == 3) ans += spec[2];
    return ans;

}


void run_case(){
    cin >> n >> m;
    FOR(i, 1, n) cin >> x[i];

    memset(spec, 0, sizeof(spec));
    FOR(i, 1, m){
        cin >> y[i];
        if (y[i] < 5) spec[y[i]]++;
    }
//    REP(i, 5) cout << spec[i] << "\n";
    sort(y + 1, y + 1 + m);
    ll ans = 0;

    FOR(i, 1, n){
//        cout << getVal(x[i]) << "\n";
        ans += getVal(x[i]);
    }
    cout << ans << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}
// Codename : Jasper the Otter



