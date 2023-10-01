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
const int MAX = 1e5 + 5;

int mp[32];

void run_case(){
//    int t; cin >> t;
    string s;
    cin >> s;
    int n = s.size();
    s = "$" + s;
    int cnt = 0;
    FOR(i, 0, 26) mp[i] = 0;
    FOR(i, 1, n) if(mp[s[i] - '0'] == 0) mp[s[i] - '0'] = 1, cnt++;
    int ans = n;
    int i = 1, j = 1;
    while (j <= n){
        mp[s[j] - '0']--; 
        if (mp[s[j] - '0'] == 0) cnt--;
        
        if (cnt == 0){
            while (cnt == 0){
  //              cout << "j i:  " << j << " "  << i << "\n";
                if (ans > j - i + 1){
                    ckmin(ans, j - i + 1);
                }
                mp[s[i] - '0']++;
                if (mp[s[i] - '0'] > 0){
                    cnt++;
                }
                i++;
            }
        }
        j++;
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



