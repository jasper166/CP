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
const int MAX = 1e4 + 5;


bool isPrime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0)
            return 0;
    }
    return (x >= 2);
}

map <string, vector <string>> adj;
map <string, bool> vis;
void prepare() {
    for (int i = 1000; i < 10000; i++) {
        if (isPrime(i)) {
            string x = to_string(i);
            string y = x;
            for (int j = 0; j < 4; j++) {
                x[j] = '*';
                adj[x].push_back(y);
                x = y;
            }
            
        }
    }
}

void run_case(){
    vis.clear();
    string s, t;
    cin >> s >> t;
    // debug(s, t);
    queue <pair <string, int>> q;
    q.emplace(s, 0);
    vis[s] = 1;
    
    while (!q.empty()) {
        auto [x, d] = q.front();
        q.pop();
        // debug(x, d);
        if (x == t) {
            cout << d << "\n";
            return;
        }
        string y = x;
        for (int j = 0; j < 4; j++) {
            x[j] = '*';
            for (auto nx : adj[x]) {
                if (!vis[nx]) {
                    q.emplace(nx, d + 1);
                    vis[nx] = 1;
                }
            }
            x = y;
        }
    }

}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    if (fopen(TASK ".inp", "r")) freopen(TASK ".inp", "r", stdin);
    
    prepare();

    int Test = 1;
    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}
