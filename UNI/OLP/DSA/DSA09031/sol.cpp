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

int n, k, m;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int vis[MAX * 2][MAX * 2];
int a[MAX * 2][MAX * 2];
ll res;
set <pii> sheeps;

int f (int x) {
    return (2 * x - 1);
}

bool isValid (int x, int y) {
    return (1 <= x && x <= n && 1 <= y && y <= n);
} 

void bfs (int u, int v) {
    queue <pii> q;
    q.emplace(u, v);
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        vis[x][y] = 1;
        // debug(x, y);
        for (int j = 0; j < 4; j++) {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if (isValid(nx, ny) && a[nx][ny] != 2 && !vis[nx][ny]) {
                // vis[nx][ny] = 1;
                q.emplace(nx, ny);
            }
        }
    }
    vector <pii> able_sheeps; 
    for (auto &s : sheeps) {   
        auto [x, y] = s;
        if (vis[x][y]) {
            able_sheeps.emplace_back(s);
        }
    }
    for (auto &s : able_sheeps) {
        sheeps.erase(s);
    }
    res += 1LL * able_sheeps.size()* sheeps.size();
}

void run_case(){
    cin >> n >> k >> m;
    n = f(n);
    for (int i = 1; i <= m; i++) {
        int u, v, s, t;
        cin >> u >> v >> s >> t;
        u = f(u); v = f(v);
        s = f(s); t = f(t);
        int x = (u + s) / 2;
        int y = (v + t) / 2;
        int rs = (u == s) * 2;
        a[x][y] = 2;
        for (int j = rs; j < rs + 2; j++) {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if (!isValid(nx, ny))
                continue;
            a[nx][ny] = 2;
        } 
    }
    vector <pii> query;
    for (int i = 1; i <= k; i++) {
        int u, v; cin >> u >> v;
        u = f(u); v = f(v);
        a[u][v] = 1;
        sheeps.insert({u, v});
        query.emplace_back(u, v);
    }
    for (auto [x, y] : query) {
        if (vis[x][y])
            continue;
        bfs(x, y);
        // debug(res);
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