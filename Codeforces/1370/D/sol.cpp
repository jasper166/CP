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
const int MAX = 2e5 + 5;

int n, k;
int a[MAX];

bool isOk(int x){
    for (int state = 0; state < 2; state++){
        int len = 0;
        for (int i = 1; i <= n; i++){
            if (len % 2 != state || a[i] <= x)
                len++;
        }
        if (len >= k) 
            return true;
    }
    return false;
}


void run_case(){
    cin >> n >> k;
    int l = INF, r = -INF;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        l = min(l, a[i]);
        r = max(r, a[i]);
    }
    
    int ans;
    while (l <= r){
        int m = (l + r) / 2;
        if (isOk(m)){
            ans = m;
            r = m - 1;
        }
        else 
            l = m + 1;
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


