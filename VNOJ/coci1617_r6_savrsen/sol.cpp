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
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#ifdef LOCAL
#include "debug.h"
#define TASK "INP"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif
#define int long long

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e7 + 5;

int prime[MAX];
int a, b;
inline void prepare(){
    for (int i = 2; i < MAX; i++) prime[i] = (i & 1)? i : 2;
    for (int i = 3; i <= sqrt(MAX); i++){
        if (prime[i] == i)
            for (int j = i * i; j < MAX; j += i) 
                prime[j] = min(prime[j], i);
    }
}

int getSum(int x){
    map <int, int> mp;
    while (x != 1){
        mp[prime[x]]++;
        x /= prime[x];
    }
    debug(mp);
    int res = 1;
    for (auto x : mp){
        int up = (pow(x.fi, x.se + 1) - 1);
        int down = (x.fi - 1);
        res *= (up/ down);
        debug(up / down);
    }
    debug(res);
    return res;
}

void run_case(){
    prepare();
    cin >> a >> b;
    ll ans = 0;
    for (int i = a; i <= b; i++) ans += abs(getSum(i) - 2 * i);
    cout << ans << "\n";

}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    if (fopen(TASK ".inp", "r")) freopen(TASK ".inp", "r", stdin);
    
    int Test = 1;
    //cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}

