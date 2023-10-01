#include "bits/stdc++.h"
// @Jasper x Powder
using namespace std;
using ll = long long;
using pii = pair < int, int >;
using ld = long double;


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



using T = pair <ld, pair<int, string> >;

T dp[MAX][2][2][2];

ld log_2(ll x){
    if (x == 0) return -INF;
    return log2(x);
}

bool compare(ld a, ld b){
    return (a > b);   
}

T memoi(string l, string r, int pos, int tight_a, int tigh_b, int st) {
    if (pos == (int) l.size())
        return make_pair(-1.00, make_pair(1, ""));

    if (dp[pos][tight_a][tigh_b][st].second.first != -1)
        return dp[pos][tight_a][tigh_b][st];

    int stight_art = tight_a ? l[pos] - '0' : 0;
    int end_art = tigh_b ? r[pos] - '0' : 9;

    ld L_ans = -INF;
    int ans = -1; 
    string s = "";
    for (int i = stight_art; i <= end_art; i++) {
        int val = i;
        // cout << val << "\n";
        if (st == 0 and i == 0)
            val = 1;
        T temp
            = memoi(l, r, pos + 1, tight_a & (i == stight_art), 
                    tigh_b & (i == end_art), st | (i > 0));


        if (compare(temp.first + log_2(val), L_ans)) {
            L_ans = temp.first + log_2(val);
            ans = (temp.second.first * val) % MOD;
            ans %= MOD;
            if (i == 0 and st == 0) 
                s = temp.second.second;
            else {
                s = temp.second.second;
                s.push_back((char) ('0' + i));
            }
        }
    }
    return dp[pos][tight_a][tigh_b][st] = make_pair(L_ans, make_pair(ans, s));
}

T solve(string L, string R){
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
                    dp[i][j][k][l].second.first = -1;
            

    T ans = memoi(L, R, 0, 1, 1, 0);
    reverse(ans.second.second.begin(), ans.second.second.end());
    return make_pair(ans.first, make_pair(ans.second.first, ans.second.second));
}

int mod(string num){
    int res = 1;
    for (int i = 0; i < num.length(); i++)
        res = (res * (int) (num[i] - '0')) % MOD;
    return res;
}

void run_case(){
    string L, R;
    cin >> L >> R;
    // if (L > R) swap(L, R);
    // cout << solve(L, R).se << "\n";
    T ans = solve(L, R);

    // if (ans.se.se.empty()){
    //     cout << "0\n";
    //     exit(0);
    // }
//    cout << "Number: " << ans.se.se << "\n";
//    cout << "Max: " << ans.se.fi << "\n";
   cout << mod(ans.se.se) << "\n";
    // cout << mod("12399999999999999999") << "\n";
}   

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
    // cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}



