#include "bits/stdc++.h"
// @Jasper
using namespace std;
using ll = long long;
using pii = pair < int, int >;

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
#else
#define debug(...) 166
#define debugArr(...) 166
#endif


const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 2e3 + 5;

struct Edge {
    int u, v, w;
};

int p[MAX];
int d[MAX];
vector <Edge> e;
int n, s;
void run_case() {
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x; cin >> x;
            if (x)
                e.push_back({i, j, x});
        }
    }

    for (int i = 1; i <= n; i++) d[i] = INF;
    d[s] = 0;
    int cnt = 1;
    for (; ;) {
        if (cnt == 2) {
            cout << d[4] << " " << d[8] << "\n";
        }
        bool have = 0;
        for (auto [u, v, w] : e) {
            if (d[u] < INF) {
                if (d[u] + w < d[v]) {
                    have = 1;
                    d[v] = d[u] + w;
                    p[v] = u;
                }
            }
        }
        if (!have) 
            break;
        cnt++;
    }

    for (int i = 1; i <= n; i++) {
        cout << "K/c " << s << " -> " << i << " = ";
        if (d[i] == INF) {
            cout << "INF";
            continue;
        }
        else 
            cout << d[i];
        cout << "; ";

        if (i == s) {
            cout << s << " <- " << s << "\n";
            continue;
        }
        vector <int> path;
        // path.push_back(i);
        int t = i;
        while (p[t]) {
            path.push_back(t);
            t = p[t];
        }
        path.push_back(s);
        for (int i = 0; i < path.size() - 1; i++)
            cout << path[i] << " <- ";
        cout << path.back();
        cout << "\n";
    }



}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;

    for (int test = 1; test <= Test; test++){

        run_case();
    }
}