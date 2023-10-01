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

int n;
string str;
int f[MAX], s[MAX], sz[MAX], dp[32][32];

void run_case(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> str;
        f[i] = str.front() - 'a';
        s[i] = str.back() - 'a';
        sz[i] = (int) str.size();
    }
    int ans = 0;
    
    for (int i = 1; i <= n; i++){
        if (dp[s[i]][f[i]])
            ans = max(ans, dp[s[i]][f[i]] + sz[i]);
        else if (f[i] == s[i]) 
            ans = max(ans, sz[i]);
        
        for (int j = 0; j < 32; j++){
            if (dp[j][f[i]])
                dp[j][s[i]] = max(dp[j][s[i]], dp[j][f[i]] + sz[i]);
        }
        dp[f[i]][s[i]] = max(dp[f[i]][s[i]], sz[i]);    
        
    }
    
    cout << ans << "\n";

}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
//    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}
// Codename : Jasper the Otter



