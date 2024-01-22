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

int n, q;
string s;
ll pre[MAX], dp[MAX];
ll ans[MAX];

void kmp(string s, int n){
    int j = 1;
    pre[1] = 0;
    for (int i = 2; i <= n; i++){
        j = pre[i - 1];
        while(j > 0 && s[j + 1] != s[i])
            j = pre[j];
        if(s[j+1] == s[i])
            pre[i] = j + 1;
        else 
            pre[i] = 0;
    }
}

void run_case(){
    cin >> s;
    n = s.size();
    s = '$' + s;

    kmp(s, n);
    int m = n;
    while(pre[m] > 0){
        ans[pre[m]] = 1;
        m = pre[m];
    }
    for (int i = 1; i <= n; i++)
        dp[i] = 1;
    for (int i = n; i >= 1; i--){
        int v = pre[i];
        if(v > 0){
            dp[v]+= dp[i];
        }
    }

    cin >> q;
    while(q--){
        int m;
        cin >> m;
            if(!ans[m] || dp[m] < 3)
                cout << "NO\n";
            else
                cout << "YES " << dp[m] << "\n";
    }
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
    // cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}
