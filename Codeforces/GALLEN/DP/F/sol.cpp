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
const int MAX = 1e3 + 5;

int n, k;

ll C(int a, int b){
    ll ret = 1;
    for (int i = 1; i <= b; i++){
        ret *= (a + 1 - i);
        ret /= i;
    }
    return ret;
}

void run_case(){
    cin >> n >> k;
    ll ans = 0;
    for (int i = 0; i <= min(k, n); i++){
        ll choose = C(n, i);
        vector <int> per;
        for (int j = 0; j < i; j++) per.push_back(j);
        int derange = 0;
        do {
           bool ok = 1;
           for (int j = 0; j < i; j++) if (per[j] == j) ok = false;
           if (ok) derange++;
        }
        while (next_permutation(per.begin(), per.end()));
        ans += choose * derange;
    }
    cout << ans << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
    //cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}
// Codename : Jasper the Otter



