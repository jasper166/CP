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
const int COL = 10 * 2 + 5;
const int ROW = 2222 * 2 + 5;

int a[ROW][COL];
int d[ROW][COL];
int m, n;
int dx[] = {-1, 1, 1, -1, 0, 0, -1, 1, 1, -1, -2, 2};
int dy[] = {-1, -1, 1, 1, -2, 2, -1, -1, 1, 1, 0, 0};

bool isValid (int x, int y){
    return (1 <= x && x <= 2 * m && 1 <= y && y < 2 * n);
}
using T = pair <int, pii>;
int dijkstra (int from_x, int from_y){
    debug(from_x, from_y);
    for (int i = 1; i <= 2 * m; i++)
        for (int j = 1; j < 2 * n; j++)
            d[i][j] = INF;

    d[from_x][from_y] = a[from_x][from_y];
    priority_queue <T, vector <T>, greater <T>> q;
    q.emplace(d[from_x][from_y], make_pair(from_x, from_y));

    while (!q.empty()){
        auto [dxy, c] = q.top();
        auto [x, y] = c;
        debug(dxy, x, y);
        q.pop();
        if (dxy > d[x][y])
            continue;
        if (x == 1)
            return dxy;
        int add = (x & 1)? 6 : 0; 
        for (int k = 0 + add; k < 6 + add; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (!isValid(nx, ny))
                continue;
            int w = a[nx][ny];
            if (d[x][y] + w < d[nx][ny]){
                d[nx][ny] = d[x][y] + w;
                q.emplace(d[nx][ny], make_pair(nx, ny));
            }
        }
    }
    return INF;
}


void run_case(){
    cin >> m >> n;
    for (int i = 1; i <= 2 * m; i++){
        if (i & 1){
            for (int j = 1; j < 2 * n; j += 2)
                cin >> a[i][j];
        }
        else {
            for (int j = 2; j < 2 * n; j += 2)
                cin >> a[i][j];
        }
    }
    int res = min(dijkstra(2 * m, 2 * n - 2), dijkstra(2 * m - 1, 2 * n - 1));
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

