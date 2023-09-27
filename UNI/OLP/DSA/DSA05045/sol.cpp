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

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

struct items {
    int v, w;
    bool operator < (const items b) const{
        return (this->v * b.w > this->w * b.v);
    }
} a[102];
int n, w;

void run_case(){
    cin >> n >> w;
    double res = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].v >> a[i].w;
    }
    sort(a + 1, a + 1 + n);
//    FOR(i, 1, n)        cout << a[i].v << " " << a[i].w << "\n";
    for (int i = 1; i <= n && w >= 0; i++) {
        debug(res);
        if (w >= a[i].w) {
            w -= a[i].w;
            res += 1.0 * a[i].v;
            continue;
        }
        double frac = 1.0 * ((double) w / (double) a[i].w);
        res += a[i].v * frac;
        w -= a[i].w * frac;
    }
    cout << fixed << setprecision(2) << res << "\n";
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

