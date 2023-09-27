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

int n, k;
int a[MAX], h[MAX];
int pre[MAX];
// dp(i, j) : maximum lectures obtained till index i at states (j = 0: sleep or j = 1: awake);
// -> answer would be dp(n, 1);

void run_case(){
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> h[i];
    
    pre[0] = 0;
    int have = 0;
    for (int i = 1; i <= n; i++){
        if (i > 1) pre[i] += pre[i - 1];
        if (h[i] == 1) 
            have += a[i];
        else 
            pre[i] += a[i];    
    }
    int add = 0;
    for (int i = k - 1; i <= n; ++i){
        add = max(add, pre[i] - (i >= k? pre[i - k] : 0));
    }
    cout << have + add << "\n";
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



