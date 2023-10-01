#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using pii = pair < int, int >;
using pll = pair < ll, ll >;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

#define Rand(a, b) uniform_int_distribution<int>(a, b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) x.begin(), x.end()

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#define debugArr(...) 42
#endif

const int INF = 1e9 + 5;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;
const ll LINF = 1e18 + 5;

int a[MAX], b[MAX];


void run_case() {
    int n = Rand(1, 10);
    int m = Rand(1, 10);
    cout << n << " " << m << "\n";
    FOR(i, 1, n) a[i] = Rand(1, 10);
    FOR(i, 1, m) b[i] = Rand(1, 10);
    FOR(i, 1, n) cout << a[i] << " \n"[i == n];
    FOR(i, 1, m) cout << b[i] << " \n"[i == m];
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    srand(time(0));
    int Test = 1;
    //    cin >> Test;
    FOR(i, 1, Test) {

        run_case();
    }
}
// Codename : Jasper the Otter