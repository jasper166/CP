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

int d[2][4] = {{2, 3, 6, 5}, {1, 2, 5, 4}};

string rotate (string x, int t) {
    string y = x;
    for (int i = 0; i < 4; i++) {
        y[d[t][i]] = x[d[t][(i + 3) % 4]];
    }
    return y;
}

void solve (string s, string t) {
    queue <pair <string, int>> q;
    q.emplace(s, 0);
    while (!q.empty()) {
        auto [x, dx] = q.front();
        q.pop();
        if (dx > 10)
            continue;
        if (x == t) {
            cout << dx << "\n";
            return;
        }
        string xr = rotate(x, 0);
        q.emplace(xr, dx + 1);
        string xl = rotate(x, 1);
        q.emplace(xl, dx + 1);
    }
}

void run_case(){
    string s = "$", t = "$";
    for (int i = 1; i <= 6; i++) {
        int x; cin >> x;
        s += (char) (x + '0');
    }
    for (int i = 1; i <= 6; i++) {
        int x; cin >> x;
        t += (char) (x + '0');
    }
    solve(s, t);
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

