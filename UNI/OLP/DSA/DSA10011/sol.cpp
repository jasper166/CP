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
const int MAX = 5e2 + 5;

int d[MAX][MAX];
int a[MAX][MAX];
int n, m;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool isValid (int x, int y) {
    return (1 <= x && x <= n && 1 <= y && y <= m);
}

void bfs () {
    using T = tuple <int, int, int>;
    priority_queue <T, vector <T>, greater <T>> q;
    d[1][1] = a[1][1];
    q.emplace(d[1][1], 1, 1);
    while (!q.empty()) {
        auto [dxy, x, y] = q.top();
        q.pop();
        if (dxy > d[x][y])
            continue;
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (!isValid(nx, ny))
                continue;
            if (d[x][y] + a[nx][ny] < d[nx][ny]) {
                d[nx][ny] = d[x][y] + a[nx][ny];
                q.emplace(d[nx][ny], nx, ny);
            }
        }
    }

}


void run_case(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    memset(d, 0x3f3f3f3f, sizeof d);
    bfs();
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         cout << d[i][j] << " \n"[j == m]; 
    //     }
    // }
    cout << d[n][m] << "\n";

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

