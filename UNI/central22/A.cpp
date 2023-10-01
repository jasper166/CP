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
const int MAX = 305;

int n, k;
string s;
int dp[MAX][MAX][MAX][2];

int winner(int l, int r, int take, int player){
    
    cout << player << "\n";

    if (take == k - 1 || l == r){
        if (s[l] == 'W' || s[r] == 'W')
            return 1;
        else 
            return 0;
    }

    if (dp[l][r][take][player] != -1)
        return dp[l][r][take][player];
    
    int ans = 0;

    if (s[l] == 'W')
        ans = max(ans, winner(l + 1, r, take, !player));
    else if (s[r] == 'W')
        ans = max(ans, winner(l, r - 1, take, !player));
        
    if (s[l] == 'B' && s[r] == 'B'){
        int turn1 = winner(l + 1, r, take + 1, !player);
        int turn2 = winner(l, r - 1, take + 1, !player);
        ans = max({ans, turn1, turn2});
    }
    return dp[l][r][take][player] = ans;
}

void run_case(){
    cin >> n >> k >> s;
    s = '&' + s;
    memset(dp, -1, sizeof(dp));
    // winner(1, n, 0, 0);
    cout << (winner(1, n, 0, 0)? "YES\n" : "NO\n");
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
    // cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}
