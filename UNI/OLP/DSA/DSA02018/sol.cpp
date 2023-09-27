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

char op[] = {'+', '-', '*'};

vector <char> f;
vector <int> a;

int cal (int x, int y, char z) {
    if (z == '+')
        return x - y;
    else if (z == '*') 
        return x / y;
    else 
        return x + y;
} 
bool ok = 0;
void solve (int i, int cur) {
    // debug(i, cur);
    if (ok)
        return;
    if (i == 4) {
        if (cur == a[4]) {
            // debug(f, a);
            ok = 1;
        }
        return;
    }
    for (int k = 0; k < 3; k++) {
        if (k == 2 && cur % a[i])
            continue;
        f.push_back(op[k]);
        solve(i + 1, cal(cur, a[i], op[k]));
        f.pop_back();
    }
}

void run_case(){
    a.resize(5);
    ok = 0;
    for (auto &x : a) cin >> x;
    sort(all(a));
    // debug(a);
     do {
        solve(0, 23);
    } while (next_permutation(all(a)));
    cout << (ok? "YES\n" : "NO\n");
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
