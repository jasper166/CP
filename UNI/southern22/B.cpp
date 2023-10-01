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
#define TASK "1311D"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

int n, m, q;
vector <pii> adj[MAX];

void run_case(){
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }
    for (int i = 1; i <= q; i++){
        char op;
        cin >> op;
        if (op == 'S'){
            int u, v, w;
            cin >> u >> v >> w;
        }
        else {
            int i, x;
            cin >> i >> x;
        }
        int i, x;#include "bits/stdc++.h"
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

pair<int, string> dp[MAX][2][2][2];

pair<int, string> memoi(string l, string r, int pos, int ta, int tb, int st) {
    if (pos == l.size())
        return { 1, "" };

    if (dp[pos][ta][tb][st].first != -1)
        return dp[pos][ta][tb][st];

    int start = ta ? l[pos] - '0' : 0;
    int end = tb ? r[pos] - '0' : 9;

    int ans = -1;
    string s = "";
    for (int i = start; i <= end; i++) {
        int val = i;
        if (st == 0 and i == 0)
            val = 1;
        pair<int, string> temp
            = memoi(l, r, pos + 1, ta & (i == start), 
                    tb & (i == end), (st | i));

        if (temp.first * val > ans) {
            ans = (temp.first % MOD * val % MOD) % MOD;
            ans %= MOD;
            if (i == 0 and st == 0) 
                s = temp.second;
            else {
                s = temp.second;
                s.push_back('0' + i);
            }
        }
    }
    return dp[pos][ta][tb][st] = { ans, s };
}

pair<int, string> solve(string L, string R){
    if (L.size() < R.size()) {
        reverse(L.begin(), L.end());
        while (L.size() < R.size())
            L.push_back('0');
        reverse(L.begin(), L.end());
    }
    for (int i = 0; i < MAX; i++) 
        for (int j = 0; j < 2; j++) 
            for (int k = 0; k < 2; k++) 
                for (int l = 0; l < 2; l++) 
                    dp[i][j][k][l].first = -1;
            

    pair<int, string> ans = memoi(L, R, 0, 1, 1, 0);
    reverse(ans.second.begin(), ans.second.end());
    return { ans.first, ans.second };
}

void run_case(){
    string L, R;
    cin >> L >> R;
    cout << solve(L, R).fi << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
    // cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}
    }

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




