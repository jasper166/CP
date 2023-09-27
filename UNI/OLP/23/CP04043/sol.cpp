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
const int MAX = 2e2 + 5;

double pi (){
    return (double) (atan(1) * 4);
}

struct data {
    int t;
    int x, y, r, h;
    double s;

    bool operator < (const data & ot) const { 
        return (s > ot.s);
    };
} a[MAX * 3];

int n, m;
int f[MAX];

void run_case(){
    cin >> n >> m;
    for (int i = 1; i <= 3 * n; i += 3){
        int x, y, z;
        cin >> x >> y >> z;
        //first cuboid
        a[i].t = 1; a[i].x = max(x, y);
        a[i].y = min(x, y); a[i].h = z;
        a[i].s = (double) (x * y);
        //second 
        a[i + 1].t = 1; a[i + 1].x = max(y, z);
        a[i + 1].y = min(y, z); a[i + 1].h = x;
        a[i + 1].s = (double) (y * z);
        //third
        a[i + 2].t = 1; a[i + 2].x = max(x, z);
        a[i + 2].y = min(x, z); a[i + 2].h = y;
        a[i + 2].s = (double) (x * z);
    }
    
    for (int i = 3 * n + 1; i <= 3 * n + m; i++){
        int r, h;
        cin >> r >> h;
        a[i].t = 2; a[i].r = r;
        a[i].h = h; 
        a[i].s = double (2 * pi() * r * r);
    }
    n *= 3;
    sort (a + 1, a + 1 + n + m);

    FOR(i, 1, n + m){debug(a[i].t, a[i].x, a[i].y, a[i].h, a[i].s)};
    
    for (int i = 1; i <= n + m; i++)
        f[i] = a[i].h;

    for (int i = 1; i <= n + m; i++){
        for (int j = 1; j < i; j++){
            if (a[i].t == a[j].t){
                if (a[i].t == 1 && a[i].x < a[j].x && a[i].y < a[j].y)
                    f[i] = max(f[i], f[j] + a[i].h);
                if (a[i].t == 2 && a[i].r < a[j].r)
                     f[i] = max(f[i], f[j] + a[i].h);
            }
            else {
                if ((a[i].x * a[i].x + a[i].y * a[i].y < 4 * a[j].r * a[j].r && a[i].s < a[j].s) 
                        || (2 * a[i].r < a[j].y && a[i].s < a[j].s))
                    f[i] = max(f[i], f[j] + a[i].h);        
            }
        }
    }
    
    int res = 0;
    for (int i = 1; i <= n + m; i++)
        res = max(res, f[i]);
    cout << res << "\n";

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

