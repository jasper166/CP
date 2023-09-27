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
const int MAX = 1e6 + 5;

int n;
string s, t;
map <string, vector <string>> adj;
map <string, bool> vis;

void bfs () {
    queue <pair <string, int>> q;
    q.emplace(s, 1);
    vis[s] = 1;
    debug(adj[s]);
    while (!q.empty()) {
        auto [u, d] = q.front();
        q.pop();
        debug(u, d);
        if (u == t) {
            cout << d << "\n";
            return;
        }
        for (int i = 0; i < (int) u.size(); i++) {
            string x = u;
            x[i] = '*';
            for (auto v : adj[x]) {
                if (!vis[v]) {
                    q.emplace(v, d + 1);
                    vis[v] = 1;
                }
            }
        }
    }
}

void run_case(){
    cin >> n >> s >> t;
    // vector <string> a;
    set <string> a;
    adj.clear();
    vis.clear();

    debug(s, t);
    for (int i = 1; i <= n; i++) {
        string x; cin >> x;
        a.insert(x);
    }
    for (int i = 0; i < (int) s.size(); i++) {
        string x = s;
        x[i] = '*';
        // debug(x);
        adj[x].push_back(s);
    }

    for (string A : a) {
        for (int i = 0; i < (int) A.size(); i++) {
            string x = A;
            x[i] = '*';
            // debug(x);
            adj[x].push_back(A);
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

