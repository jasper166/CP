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
const int MAX = 2e5 + 5;

int n;
int a[MAX], used[MAX];

void run_case(){
    cin >> n;
    FOR(i, 1, n){
        cin >> a[i];
        used[i] = 0;
    }
    int ans = 0;
    bool ok = 0;
    FOR(i, 1, n){
        if (used[i])
            continue;
        vector <int> f;
        int x = i;
        while (!used[x]){
            used[x] = 1;
            f.push_back(x);
            x = a[x];
        }
        ans += (int) f.size() - 1;
        sort(all(f));
        REP(j, (int) f.size() - 1)
            if (abs(f[j] - f[j + 1]) == 1)
                ok = 1;
    }
    if (ok) 
        ans--;
    else 
        ans++;
    cout << ans << "\n";
        
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


