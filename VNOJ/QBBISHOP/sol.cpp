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
const int MAX = 2e2 + 5;

int vis[MAX][MAX];
int n, m, u, v, s, t;
int dx[] = {1, 1, -1, -1};
int dy[] = {1, -1, 1, -1};

bool isOk(int x, int y){
    return (1 <= x && x <= n && 1 <= y && y <= n && !vis[x][y]);
}

void run_case(){
    cin >> n >> m >> u >> v >> s >> t;
    for (int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        vis[x][y] = 1;
    }
    queue <pii> q;
    q.emplace(u, v);    
    vis[u][v] = 1;
    while (!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        for (int k = 0; k < 4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            while (isOk(nx, ny)){
                vis[nx][ny] = vis[x][y] + 1;
                q.emplace(nx, ny);
                nx = nx + dx[k];
                ny = ny + dy[k];
            }
        }
    }
    cout << vis[s][t] - 1 << "\n";
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

