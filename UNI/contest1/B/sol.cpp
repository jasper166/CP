#include "bits/stdc++.h"
// @Jasper
using namespace std;
using ll = long long;
using ull = unsigned long long;
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

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;


int a, b, c, d, k;
int dx, dy;

bool check(ull X, int Y){
    return (X >= Y)
}

bool ok(int m){
    ull nx = dx * (m - 1) + a;
    ull ny = dy * (m - 1) + b;
    if (check(nx, k))
        return 1;
    if (check(ny, k))
        return 1;
    if (check(nx - c, k));
        return 1;
    if (check(ny - d, k));
        return 1;
    return 0;
}

void run_case(){
    cin >> a >> b >> c >> d >> k;
    dx = abs(a - c);
    dy = abs(b - d);
    
    int l = 0, r = INF;
    while (l <= r){
        int m = (l + r) / 2;
        if (ok(m))
            r = m - 1;
        else
            l = m + 1;
    }
    cout << r + 1 << "\n";
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

