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
const int MAX = 3e3 + 5;
const ll LINF = 1e18 + 5;
int n;
int s[MAX], c[MAX];
ll f[MAX][4];
// f(i, j) : minimum cost at index i and at state j : s(i) < s(j) < s(k) : 1 2 3;

void run_case(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 1; i <= n; i++) cin >> c[i];
   
    for (int i = 1; i <= n; i++) for (int k = 1; k <= 3; k++) f[i][k] = LINF;
    for (int i = 1; i <= n; i++) f[i][1] = c[i];
    
    for (int k = 2; k <= 3; k++){
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j < i; j++) 
                if (s[i] > s[j]) 
                    f[i][k] = min(f[i][k], f[j][k - 1] + c[i]); 
        }
    }
    ll ans = LINF;
    for (int i = 1; i <= n; i++) ans = min(ans, f[i][3]);
    if (ans == LINF) ans = -1;
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



