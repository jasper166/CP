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
const int MAX = 1e3 + 5;


int n, m, q;
int f[MAX][MAX];
int res[MAX * 10];
int color, comp;
vector <pii> adj[MAX * 10];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

struct DisjointSets {
    int p[MAX * MAX];
    int n, m;
    DisjointSets (int N, int M) {
        this->n = N;
        this->m = M;
        memset(p, 0, sizeof p);
    }

    int get (int u) {
        return (p[u] == 0? u : p[u] = get(p[u]));
    }

    // merging two color 
    void unite (int u, int v) {
        if (u == 0 || v == 0)
            return;
        u = get(u);
        v = get(v);
        if (u == v)
            return;
        p[v] = u;
        comp--;
    }
    // whenever painting a cell we create a new component 
    //if and only if its 4 neighbours if not painted (0) or painted in the same color
    void paint (int x, int y) {
        comp++;
        f[x][y] = color;
        // merging current cell with other 4 neighbours
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (1 <= nx && nx <= n && 1 <= ny && ny <= m)
                unite (color, f[nx][ny]);
        }
        color++;
    }
};



void run_case(){
    cin >> n >> m >> q;
    // store each slide to use later for recoloring
    for (int i = 1; i <= q; i++) {
        int x, y, X, Y;
        cin >> x >> y >> X >> Y;
        for (int r = x; r <= X; r++) {
            for (int c = y; c <= Y; c++) {
                if (!f[r][c]) {
                    f[r][c] = i;
                    adj[i].push_back({r, c});
                }
            }
        }
    }
    // other white cells is painted as (q + 1) color
    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= m; c++) {
            if (!f[r][c]) {
                f[r][c] = q + 1;
                adj[q + 1].push_back({r, c});
            }
        }
    }
    // begin to color in reversed order
    memset(f, 0, sizeof f);
    color = 1;
    comp = 0;
    DisjointSets dsu(n, m);

    for (int i = q + 1; i >= 1; i--) {
        for (auto& [x, y] : adj[i]) {
            dsu.paint(x, y);
        }
        res[i - 1] = comp;
    }
    for (int i = 1; i <= q; i++) cout << res[i] << "\n";
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
