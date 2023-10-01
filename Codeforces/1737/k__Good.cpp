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
#define countigh_bit(a) __builtin_popcount(a)
#define sum(l,r,val) accumulate(l,r,val)
#define len(s) (int)s.size()

#ifdef LOCAL
#include "debug.h"
#define tight_aSK "61E"
#else
#define debug(...) 42
#define tight_aSK "printer"
#define debugArr(...) 42
#endif

#define int long long

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 2;

pair<int, string> dp[MAX][2][2][2];

pair<int, string> memoi(string l, string r, int pos, int tight_a, int tigh_b, int st) {
    if (pos == (int) l.size())
        return make_pair(1, "");

    if (dp[pos][tight_a][tigh_b][st].first != -1)
        return dp[pos][tight_a][tigh_b][st];

    int stight_art = tight_a ? l[pos] - '0' : 0;
    int end_art = tigh_b ? r[pos] - '0' : 9;

    int ans = -1;
    string s = "";
    for (int i = stight_art; i <= end_art; i++) {
        int val = i;
        // cout << val << "\n";
        if (st == 0 and i == 0)
            val = 1;
        pair<int, string> temp
            = memoi(l, r, pos + 1, tight_a & (i == stight_art), 
                    tigh_b & (i == end_art), st | (i > 0));

        if (temp.first * val > ans) {
            ans = (temp.first % MOD * val % MOD) % MOD;
            ans %= MOD;
            if (i == 0 and st == 0) 
                s = temp.second;
            else {
                s = temp.second;
                s.push_back((char) ('0' + i));
            }
        }
    }
    return dp[pos][tight_a][tigh_b][st] = make_pair(ans, s);
}

pair<int, string> solve(string L, string R){
    if (L.size() < R.size()) {
        reverse(L.begin(), L.end());
        while (L.size() < R.size())
            L.push_back('0');
        reverse(L.begin(), L.end());
    }
    // cout << L << "\n";
    // cout << R << "\n";
    for (int i = 0; i < MAX; i++) 
        for (int j = 0; j < 2; j++) 
            for (int k = 0; k < 2; k++) 
                for (int l = 0; l < 2; l++) 
                    dp[i][j][k][l].first = -1;
            

    pair<int, string> ans = memoi(L, R, 0, 1, 1, 0);
    reverse(ans.second.begin(), ans.second.end());
    return make_pair(ans.first, ans.second);
}

int digitProduct(int i){
    int ans = 1;
    while (i){
        ans = ans * (i % 10);
        i /= 10;
    }
    return ans;
}

void run_case(){
    // string L, R;
    // cin >> L >> R;
    // cout << solve(L, R).se << "\n";
    // pair <int, string> ans = solve(L, R);
    // cout << "Number: " << ans.se << "\n";
    // cout << "Max: " << ans.fi << "\n";
    // cout << ans.fi << "\n";
    int L, R;
    cin >> L >> R;
    int ans = -INF;
    for (int i = L; i <= R; i++){
        int x = digitProduct(i);
        cout << x << "\n";
        if (x > ans)
            ans = x;
    }
    cout << ans << "\n";
}   

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
    // cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}
