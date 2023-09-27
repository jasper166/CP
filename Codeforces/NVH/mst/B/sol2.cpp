#include "bits/stdc++.h"
// @Jasper
using namespace std;
using ll = long long;
using pii = pair < int, int >;

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
#else
#define debug(...) 42
#define debugArr(...) 42
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 5e3 + 5;

using T = pair <double, int>;
int n, m;
vector <T> adj[MAX];
double d[MAX], w[MAX][MAX];
bool used[MAX], have[MAX][MAX];

struct Point {
    int x, y;
}a[MAX];

double dis (Point x, Point y) {
    return sqrt((x.x - y.x) * (x.x - y.x) + (x.y - y.y) * (x.y - y.y));
}


void push (int u) {
    used[u] = 1;
    for (int v = 1; v <= n; v++) {
        if (v != u) {
            double W = w[u][v];
            if (!used[v] && W < d[v]) 
                d[v] = W;
        }
    }
}

double Prim (int s) {
    for (int i = 1; i <= n + 1; i++) d[i] = 1e9 + 0.5;
    memset(used, 0, sizeof used);
    push(s);
    d[s] = 0.00;
    double res = 0;

    while (1) {
        int u = -1;
        for (int i = 1; i <= n; i++) {
            if (!used[i] && d[i] < d[u]) 
                u = i;
        }
        if (u == -1)
            break;
        res += d[u];
        push(u);
    }
    return res;
}

void run_case() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;
    
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        have[u][v] = have[v][u] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
           if (have[i][j])
                w[i][j] = w[j][i] = 0.00;
            else
                w[i][j] = w[j][i] = dis(a[i], a[j]);
        }
    }
    cout << fixed << setprecision(2) << Prim(1) << "\n"; 
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

