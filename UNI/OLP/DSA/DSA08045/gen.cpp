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

void run_case(){
    int n = uid(1, 5);
    int m = uid(1, 6);
    cout << n << " " << m << "\n";
    FOR(i, 1, n){
        int op = uid(1, 2);
        int x = uid(-10, 10);
        int y = uid(-10, 10);
        int X = uid(-10, 10);
        int Y = uid(-10, 10);
        if (op == 1)
            x = X;
        else 
            y = Y;
        cout << x << " " << y << " " << X << " " << Y << "\n";
    }
    FOR(i, 1, m){
        int x = uid(-10, 10);
        int y = uid(-10, 10);
        cout << x << " " << y << "\n";
    }

}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    if (fopen(TASK ".inp", "r")) freopen(TASK ".inp", "r", stdin);
    
    int Test = 1;
    cout << Test << "\n";
    //cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}

