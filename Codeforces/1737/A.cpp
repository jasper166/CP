#include "bits/stdc++.h"
// @Jasper


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

int n, k;
string s;

void run_case(){
    cin >> n >> k >> s;
    s = '$' + s;
    int m = n / k;
    string ans = "";
    vector <int> cnt(26, 0);
    FOR(i, 1, n) cnt[s[i] - 'a']++;
    FOR(i, 1, k){
        int l = n / k;
        for(int j = 0; l >= 0; j++)
            if(cnt[j] && l > 0){
                l--;
                cnt[j]--;
            }
            else {
                ans += char (j + 'a');
                break;
            }
    }
    cout << ans << '\n';
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}

