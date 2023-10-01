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
const int MAX = 1e2 + 5;
const ll LINF = 1e18;

ll xs, ys, xe, ye, n;
string s; 

pair <ll, ll> f[MAX];
pair <ll, ll> get(char x) {
    if (x == 'U')return {0, 1};
    if (x == 'D')return {0, -1};
    if (x == 'L')return {-1, 0};
    if (x == 'R')return {1, 0};
    return {0, 0};
}
bool ok (ll x) {
    ll u = xs, v = ys;
    u += f[n].fi * (x / n);
    v += f[n].se * (x / n);
    u += f[x % n].fi;
    v += f[x % n].se;
    ll ans = abs(u - xe) + abs(v - ye);
    return (ans <= x);
}

void run_case(){

    cin >> xs >> ys >> xe >> ye >> n >> s;
    s = '$' + s;
    ll L = 0, R = 1e18, ans = LINF;

    FOR(i, 1, n){
        auto [xd, yd] = get(s[i]);
        f[i].fi = f[i - 1].fi + xd;
        f[i].se = f[i - 1].se + yd;
    }

    while (L <= R){
        ll M = (L + R) / 2;
        if (ok(M)){
            ans = M;
            R = M - 1;
        }
        else
            L = M + 1;
    }
    if (ans == LINF) ans = -1;
    cout << ans << '\n';

}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
    // cin >> Test;
    FOR (i, 1, Test){

        run_case();
    }
}
// Codename : Jasper the Otter


