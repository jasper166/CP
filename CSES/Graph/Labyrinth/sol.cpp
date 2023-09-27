#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using pii = pair < int, int >;
using pll = pair < ll, ll >;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) x.begin(), x.end()

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#define debugArr(...) 42
#endif

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e3 + 5;

int n, m;
char a[MAX][MAX];
pii s, e;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int d[MAX][MAX];
pii p[MAX][MAX];
char dir[] = {'L', 'R', 'U', 'D'};
bool vis[MAX][MAX]; 

bool isOk(int x, int y){
    return (1 <= x && x <= n && 1 <= y && y <= m && !vis[x][y] && a[x][y] != '#'); 
}

void run_case(){
    cin >> n >> m;
    FOR(i, 1, n) FOR(j, 1, m){
        cin >> a[i][j];
        if (a[i][j] == 'A') s = {i, j};
        else if (a[i][j] == 'B') e = {i, j};
    }
    /*
    cout << s.fi << " " << s.se << "\n";
    cout << e.fi << " " << e.se << "\n";
    */
    using T = tuple <int, int>;
    queue <T> q;
    FOR(i, 1, n) FOR(j, 1, m) d[i][j] = -1;
    q.push({s.fi, s.se});
    vis[s.fi][s.se] = 1;
    while (!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        if (make_pair(x, y) == e) break;
        REP(i, 4){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int now = i;
            if (isOk(nx, ny)){
                vis[nx][ny] = 1;
                d[nx][ny] = now;
                p[nx][ny] = {x, y};
                q.push({nx, ny});
            }
        }
    }
/*
    FOR(i, 1, n) FOR(j, 1, m){
        if (a[i][j] == '.' && d[i][j] != -1){
            cout << dir[d[i][j]]; 
        }
        else cout << a[i][j];
        if (j == m) cout << "\n";
    }
    */
    auto [x, y] = e;
    if (d[x][y] == -1) cout << "NO\n", exit(0);
    vector <char> path;
    while (e != s){
        auto [x, y] = e;
        path.push_back(dir[d[x][y]]);
        e = p[x][y];     
    }
    reverse(all(path));
    cout << "YES\n" <<  path.size() << "\n";
    for (char c : path) cout << c;
    cout << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
//    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}
// Codename : Jasper the Otter



