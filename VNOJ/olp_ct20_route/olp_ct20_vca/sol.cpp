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
const int MAX = 1e6 + 5;

int n, k;
string s;
int cnt[320];

void run_case(){
    cin >> k >> s;
    n = s.size();
    s = '$' + s;
    int ans = INF;
    //int l = 1, r = 1;
    for (int l = 1, r = 1; l <= n; l++){
        
        while (r < n && (cnt['A'] < k || cnt['C'] < k || cnt['V'] < k)){
            cnt[s[r]]++;
            r++;
        }
        if (cnt['A'] < k || cnt['C'] < k || cnt['V'] < k) continue;
        int toRemove = 0;
        toRemove = cnt['A'] + cnt['C'] + cnt['V'] - 3 * k;
        //if (toRemove < 0) break;
        debug(l, r, toRemove);
        ans = min(ans, toRemove);
        cnt[s[l]]--;
    }
    cout << ans << "\n";
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

