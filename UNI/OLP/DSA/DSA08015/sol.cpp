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
const int MAX = 50 + 5;

char a[MAX][MAX][MAX];
int d[MAX][MAX][MAX];
int nW, nH, nD;

using T = tuple <int, int, int>;
T st, en;

int dx[] = {0, 0, -1, 1, 0, 0};
int dy[] = {-1, 1, 0, 0, 0, 0};
int dz[] = {0, 0, 0, 0, -1, 1};

bool isValid (int x, int y, int z) {
    return (1 <= x && x <= nD && 1 <= y && y <= nW && 1 <= z && z <= nH && d[x][y][z] == -1 && a[x][y][z] != '#');
}

void bfs () {
    memset(d, -1, sizeof d);
    
    queue <T> q;    
    q.emplace(st);
    auto [ex, ey, ez] = en; 
    auto [sx, sy, sz] = st;
    d[sx][sy][sz] = 0;
  //  debug(sx, sy, sz, ex, ey, ez);

    while (!q.empty()) {
        auto [x, y, z] = q.front();
        q.pop();
        
        if (x == ex && y == ey && z == ez)
            break;
//        debug(x, y, z);
        for (int k = 0; k < 6; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            int nz = z + dz[k];
            if (isValid(nx, ny, nz)) {
                d[nx][ny][nz] = d[x][y][z] + 1;
                q.emplace(nx, ny, nz);
            }
        }
    }

    cout << d[ex][ey][ez] << "\n";
}

void run_case() {
    cin >> nH >> nD >> nW;
    for (int k = 1; k <= nH; k++) {
        for (int i = 1; i <= nD; i++) {
            for (int j = 1; j <= nW; j++) {
                cin >> a[i][j][k];
                if (a[i][j][k] == 'S')
                    st = {i, j, k};
                else if (a[i][j][k] == 'E')
                    en = {i, j, k};
            }
        }
    }
    bfs();
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

