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

int n;
char a[MAX][MAX];
int d[MAX][MAX];
pii st, en;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool isValid (int x, int y) {
    return (1 <= x && x <= n && 1 <= y && y <= n && a[x][y] == '.' && d[x][y] == -1);
}

queue <pii> q;
void add (int x, int y, int X, int Y, int valX, int valY) {
    while (isValid(X, Y)) {
            d[X][Y] = d[x][y] + 1;
            q.emplace(X, Y);
            X += valX;
            Y += valY;
        }
}

void run_case(){
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    cin >> st.fi >> st.se >> en.fi >> en.se;
    st.fi++; st.se++; en.fi++; en.se++;

    memset(d, -1, sizeof d);
    q.push(st);
    d[st.fi][st.se] = 0;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        if (d[x][y] == -1)
            continue;
        add (x, y, x + 1, y, 1, 0);
        add (x, y, x - 1, y, -1, 0);
        add (x, y, x, y + 1, 0, 1);
        add (x, y, x, y - 1, 0, -1);
    }
    cout << d[en.fi][en.se] << "\n";
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

