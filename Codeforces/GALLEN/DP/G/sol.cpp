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
const int MAX = 2005;


int s, t, n, d;
ll f[3005][105];
// f(i, j) maximum path till j second and ending at i speed; -> ans = f(t, n);
void run_case(){
    cin >> s >> t >> n >> d;
    
    memset(f, 0, sizeof(f));
    f[s][1] = s;
    for (int i = 1; i < n; i++){
        for (int j = 0; j < MAX; j++){
            if (f[j][i] == 0) continue;
            for (int k = max(0, j - d); k <= j + d; k++)
                f[k][i + 1] = max(f[k][i + 1], f[j][i] + k); 
        }
    }
    cout << f[t][n] << "\n";
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



