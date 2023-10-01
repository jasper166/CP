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
const ll LINF = 1e18 + 5;

ll L, R;

ll cal(ll x, ll i){
	if(x < i) return x + 1;
	ll cur = x / i; 
	ll ans = (cur - cur / 2) * i;
	if(cur % 2 == 0) ans += x - (cur * i) + 1;
	return ans;
}


void run_case(){
	cin >> L >> R;
	ll ans = LINF;
	for (ll i = 2; i <= R; i *= 2){
		ans = min(ans, cal(R, i) - cal(L - 1, i));
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




