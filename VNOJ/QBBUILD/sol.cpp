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
const int MAX = 1e2 + 5;

int n;
int d[MAX][MAX];
vector <int> city;

void run_case(){
    cin >> n;
    for (int i = 1; i <= 4; i++){
        int x; cin >> x;
        city.push_back(x);
    }
    for (int u = 1; u <= n; u++)
        for (int v = 1; v <= n; v++){
            d[u][v] = (u == v)? 0 : INF;
        }
    int u, v, w;
    while (cin >> u >> v >> w){
        d[u][v] = min(d[u][v], w);
        d[v][u] = min(d[u][v], w);
    }
    
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    int res = INF;
    debug(city);
    sort(all(city));
    do {
        int cur = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++){
                cur = (d[i][city[0]] + d[i][city[1]] + d[i][j] + d[j][city[2]] + d[j][city[3]]);
                res = min(res, cur);     
            }
    }
    while (next_permutation(all(city)));
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

