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

int n;
struct fields{
    int x, y, r;
}a[12];

void run_case(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i].x >> a[i].y >> a[i].r;
        a[i].x *= 10;
        a[i].y *= 10;
        a[i].r *= 10;
    }
    int ans = 0;
    for (int x = -100; x <= 200; x++)
        for (int y = -100; y <= 200; y++){
            int cnt = 0;
            for (int i = 1; i <= n && !cnt; i++){
                int X = (a[i].x - x);
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

int n;
struct fields{
    int x, y, r;
}a[12];

void run_case(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i].x >> a[i].y >> a[i].r;
        a[i].x *= 10;
        a[i].y *= 10;
        a[i].r *= 10;
    }
    int ans = 0;
    for (int x = -100; x <= 200; x++)
        for (int y = -100; y <= 200; y++){
            for (int i = 1; i <= n; i++){
                int X = (a[i].x - x);
                int Y = (a[i].y - y);
                int R = (a[i].r);
                if (X * X + Y * Y <= R * R)
                    ans++;
            }
        }
    cout << fixed << setprecision(10) << ans / 100.0 << "\n";
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

                int Y = (a[i].y - y);
                int R = (a[i].r);
                if (X * X + Y * Y <= R * R){
                    cnt++;
                };             
            }
            ans += cnt;
        }
    cout << fixed << setprecision(10) << ans / 100.0 << "\n";
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


