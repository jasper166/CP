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

int n, a[MAX];

void run_case(){
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    sort(a + 1, a + 1 + n);
    
    vector <int> d;
    int m = a[n] - a[1];
    for (int i = 1; i * i <= m; ++i){
        if (m % i == 0){
            d.push_back(i);
            if (i != m / i) 
                d.push_back(m / i);
         }
    }
    int ans = 0;
  
    for (int i = 0; i < (int) d.size(); i++){
        int tmp = a[1] % d[i];
        int j;
        for (j = 2; j <= n; j++) if (a[j] % d[i] != tmp) break;
        if (j == n + 1) ans++;
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



