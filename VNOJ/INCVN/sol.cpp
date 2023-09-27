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
const int MOD = 5e6;
const int MAX = 1e4 + 5;

struct fenwick {
    int f[55][MAX];
    int N, K;
    fenwick (int N, int K) {
        this->N = N;
        this->K = K;
        memset(f, 0, sizeof f);
    }

    int get (int x, int K){
        int res = 0;
        for (; x; x -= (x & -x)){
            res += f[K][x];
            res %= MOD;
        }
        return res;
    }

    void update (int x, int K, int val) {
        for (; x < MAX; x += (x & -x)){
            f[K][x] += val;
            f[K][x] %= MOD;
        }
    }
};

int n, k;
int a[MAX];
int f[55][MAX];

void run_case(){
    cin >> n >> k;
    vector <int> b;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        f[1][i] = 1;
        b.push_back(a[i]);
    }
    
    sort(all(b));
    for (int i = 1; i <= n; i++)
        a[i] = (int) (lower_bound(all(b), a[i]) - b.begin()) + 1;
    debugArr(a, 1, n);
    fenwick BIT(n, k);    
    
    for (int i = 2; i <= k; i++){
        for (int j = 1; j <= n; j++){
            f[i][j] = BIT.get(a[j] - 1, i - 1);
            BIT.update(a[j], i - 1, f[i - 1][j]);
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++){
        res += f[k][i];
        res %= MOD;
    }
    cout << res << "\n";


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

