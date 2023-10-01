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

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int nR, nC;
int a[MAX][MAX];

queue <pair <int, pii>> q;

bool isValid (int x, int y) {
    return (1 <= x && x <= nR && 1 <= y && y <= nC && a[x][y] == 1);
}

int bfs () {
    int res = -1;
    while (!q.empty()) {
        auto [d, xy] = q.front();
        auto [x, y] = xy;
        q.pop();
        res = max(d, res);
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (!isValid(nx, ny))
                continue;

            a[nx][ny] = 2;
            q.emplace(d + 1, make_pair(nx, ny));
        }
    }
    return res;
}


void run_case(){
    cin >> nR >> nC;
    for (int i = 1; i <= nR; i++)
        for (int j = 1; j <= nC; j++) 
            cin >> a[i][j];

    for (int i = 1; i <= nR; i++)
        for (int j = 1; j <= nC; j++)
            if (a[i][j] == 2)
                q.emplace(0, make_pair(i, j));

    int res = bfs();
    
    for (int i = 1; i <= nR; i++)
        for (int j = 1; j <= nC; j++)
            if (a[i][j] == 1)
                res = -1;
    cout << res << "\n";
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

