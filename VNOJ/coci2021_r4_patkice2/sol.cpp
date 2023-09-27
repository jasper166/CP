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
const int MAX = 2e3 + 5;

int n, m;
char a[MAX][MAX];
int d[MAX][MAX];
pii trace[MAX][MAX];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
char in[] = {'>', '<', 'v', '^'};
char fix[] = {'<', '>', '^', 'v'};
//char fix[] = {}
pii st, en;

bool isValid(int x, int y){
    char c = a[x][y];
    return (1 <= x && x <= n && 1 <= y && y <= m && c != 'x');
}

void bfs(int rx, int ry){
    memset(d, 0x3f3f3f3f, sizeof d);
    FOR(i, 1, n) FOR(j, 1, m) trace[i][j] = {-1, -1};
    d[rx][ry] = 0;
    
    deque <pii> q;
    q.push_front({rx, ry});
    while (!q.empty()){
        if (q.front() == st) 
            break;
        auto [x, y] = q.front();
     //   debug(x, y, d[x][y]);
        q.pop_front();
        for (int k = 0; k < 4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (!isValid(nx, ny)) 
                continue;
            int w = (a[nx][ny] != in[k]);
            if (a[nx][ny] == 'o') w = 0;
            if (d[x][y] + w < d[nx][ny]){
                d[nx][ny] = d[x][y] + w;
                trace[nx][ny] = {x, y};
                if (w == 1){
                    q.push_back({nx, ny});
                }
                else{
                    q.push_front({nx, ny});
                }
            }
        }
    }
}

void run_case(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
            if (a[i][j] == 'o')
                st = make_pair(i, j);
            else if (a[i][j] == 'x')
                en = make_pair(i, j);
        }
    bfs(en.fi, en.se);
    cout << d[st.fi][st.se] << "\n";
    pii cur = st;
    while (cur != en){
        auto [x, y] = cur;
    //    debug(cur);
        pii to = trace[x][y];
        for (int k = 0; k < 4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx == to.fi && ny == to.se){
                if (a[x][y] != 'o')
                    a[x][y] = fix[k];
                cur = to;
            }
        }
    }
    a[en.fi][en.se] = 'x';
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++)
            cout << a[i][j];
        cout << "\n";
    }

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

