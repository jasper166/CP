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
const int MAX = 1e5 + 5;


int n, k;
pair < int, int > a[MAX];
long long dp[11][MAX], BIT[11][MAX];
void update(int p, int index, long long val){
    for(;index < MAX; index += (-index) & index)
        BIT[p][index] += val;
}
long long get(int p, int index){
    long long ans = 0;
    for(;index > 0; index -= (-index) & index)
        ans += BIT[p][index];
    return ans;
}
void run_case(){
    cin >> n >> k;
    for(int i = 1; i <= n; i ++){
        cin >> a[i].fi >> a[i].se;
        a[i].se++;
    }

    sort(a + 1, a + n + 1, [](pair < int, int > x, pair < int, int > y){
        return (x.fi < y.fi) || (x.fi == y.fi && x.se > y.se);
    });

    dp[0][0] = 1;
    update(0, 1, 1);
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= k; j ++){
            dp[j][i] = get(j - 1, a[i].se - 1);
            update(j, a[i].se, dp[j][i]);
        }
    }

    cout << sum(dp[k] + 1, dp[k] + n + 1, 0LL);
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
    // cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}
