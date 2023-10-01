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
const int MAX = 5;

char a[MAX][MAX];
int k, n, m;
map <string, bool> dic;
vector <string> ans;
bool vis[MAX][MAX];

int dx[] = {0, 0, -1, 1, 1, 1, -1, -1};
int dy[] = {-1, 1, 0, 0, -1, 1, -1, 1};

bool isValid (int x, int y) {
    return (1 <= x && x <= n && 1 <= y && y <= m && !vis[x][y]);
}

void solve (int x, int y, string cur) {
    if (dic.find(cur) != dic.end()) {
        ans.push_back(cur);
        return;
    }
    // debug(x, y, cur);
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!isValid(nx, ny))
            continue;
        vis[x][y] = 1;
        solve (nx, ny, cur + (char) a[nx][ny]);
        vis[x][y] = 0;
    }
}

void run_case(){
    cin >> k >> n >> m; 
    dic.clear();
    ans.clear();

    for (int i = 1; i <= k; i++) {
        string x; cin >> x;
        dic[x] = i;
    }
    // debug(dic);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    // for (int i = 1; i <= n; i++)
    //     for (int j = 1; j <= m; j++)
    //         cout << a[i][j] << " \n"[j == m];

    
    // solve(1, 1, st);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            string st;
            st += (char) a[i][j];
            solve(i, j, st);
        }
    }

    if (ans.empty()) 
        cout << "-1\n";
    else {
        sort(all(ans), [] (const string x, const string y) {
            return dic[x] < dic[y];
        });
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
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

