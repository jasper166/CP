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
const int MAX = 1e6 + 5;

ll w, c;

int f[] = {0, 1, 1, 1, 2, 1, 2, 2, 2, 3};
int g[] = {1, 1, 1, 1, 2, 1, 2, 1, 1, 3};

int g5[] = {1, 2, 1, 1, 3};

void run_case(){
    cin >> w >> c;
    if (w % 1000){
        cout << 0 << "\n";
        return;
    }
    w /= 1000;
    pair <ll, ll> res = {0, 1};
    while (w && c--) {
        res.fi += f[w % 10];
        res.se *= g[w % 10];
        w /= 10;
    }

    if (w) {
        int int_part = w / 5;
        int rem = w % 5;
        res.fi += int_part + f[rem];
        res.se *= (w > 5)? g5[rem] : g[rem];      
        // rem = 0? -> (1, 0);
        // rem = 1? -> (1, 1) to 1 and (2, 2) with remains
        // rem = 2? 2, 7, 12, 17 -> (1, 1) to 2 and (2, 1) with remains;
        // rem = 3? 3, 8, 13, 18 -> (1, 1) to 3 and (2, 1) with remains;
        // rem = 4? 4, 9, 14, 19 -> (2, 2) to 4 and (3, 3) to remains;
    }

    cout << res.fi << " " << res.se << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    if (fopen(TASK ".inp", "r")) freopen(TASK ".inp", "r", stdin);
    
    int Test = 1;
    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}

