#include "bits/stdc++.h"
// @Jasper x Powder
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
#define el "\n"
#define LL long long
#define bit(a,b) ((a >> b)&1)
#define countBit(a) __builtin_popcount(a)
#define sum(l,r,val) accumulate(l,r,val)
#define len(s) (int)s.size()

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

ll n, k;
ll a[MAX];
ll pre[MAX];
ll dp[MAX][2];
ll s[MAX];

void run_case(){
    cin >> n >> k;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	for (int i = 1; i <= n; i++){
		s[i] = pre[i] = 0;
		dp[i][0] = dp[i][1] = 0;
	}
	for (int i = 1; i <= n; i++)
		pre[i] = pre[i - 1] + a[i];
	for (int i = 1; i + k - 1 <= n; i++)
		s[i] = pre[i + k - 1] - pre[i - 1];
	ll ans = -LINF;
	for (int i = 1; i + k - 1 <= n; i++){
		dp[i][1] = max(dp[i - 1][1], dp[i - k][0] + s[i]);
        dp[i][0] = max(dp[i - 1][0], dp[i - k][1] - s[i]);
		ans = max({ans, dp[i][1], dp[i][0]});
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
