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
const int MAX = 1e5 + 5;

int n, a[MAX];

void getAns (pii pos) {
    for (int i = n; i >= 1; i--)
        if (i != pos.fi && i != pos.se)
            cout << a[i];
    cout << "\n";
    return;
}

void solve (int rem) {
    
    pii p = {0, 0};
    for (int i = 1; i <= n; i++) {
        if (a[i] % 3 == rem) {
            getAns({i, i});
            return;
        }
        else if (a[i] % 3 == 3 - rem) {
            if (p.fi == 0)
                p.fi = i;
            else if (p.se == 0)
                p.se = i;
        }
    }
    // debug(rem, p);
    if (p.fi && p.se && n >= 3)
        getAns(p);
    else 
        cout << "-1\n";
    
}
// countingSort
int f[10];
void Sort() {
    memset(f, 0, sizeof f);
    for (int i = 1; i <= n; i++) {
        f[a[i]]++;
    }
    int j = 1;
    for (int i = 0; i < 10; i++) {
        while (f[i]) {
            a[j++] = i;
            f[i]--;
        }
    }
    // for (int i = 1; i <= n; i++)
    //     cout << a[i] << " \n"[i == n];
}

void run_case(){
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    Sort();
    int sum = accumulate(a + 1, a + 1 + n, 0);
    if (sum % 3 == 0) 
        getAns({0, 0});
    else 
        solve(sum % 3);
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

