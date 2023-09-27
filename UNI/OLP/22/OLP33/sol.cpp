#include "bits/stdc++.h"
// @Jasper
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

#ifdef LOCAL
#include "debug.h"
#define TASK "OLP33"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

int d[MAX];
int a, b;
map <int, int> mp;

void prepare(){
    for (int i = 1; i < MAX; i++)
        d[i] = (i & 1)? i : 2;
    for (int i = 3; i <= sqrt(MAX); i++){
        if (d[i] == i)
            for (int j = i * i; j < MAX; j += i)
                d[j] = min(d[j], i);
    }
}

void factorize(int x){
    while (x != 1){
        mp[d[x]]++;
        x /= d[x];
    }
}

void run_case(){
    mp.clear();
    cin >> a >> b;
    for (int i = a; i <= b; i++)
        factorize(i);
    ll ans = 1;
//    debug(mp);
    for (auto x : mp){         
        ans *= (2 * x.se + 1) * 1LL;
        if (ans >= MOD) ans -= MOD;
    }
    cout << ans << "\n";

}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    if (fopen(TASK ".inp", "r"))
        freopen(TASK ".inp", "r", stdin);
    
    prepare();

    int Test = 1;
    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}




