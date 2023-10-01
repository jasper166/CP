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
const int MAX = 1e5 + 5;

vector<bool> check;
vector <vector<int>> a;
void bfs(int n) {
    queue<int> q;
    q.push(n);
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (auto v : a[u])
        {
            if (check[v])
            {
                check[v] = 0;
                q.push(v);
            }
        }
    }
}

void run_case(){
    int n, m, x, y, stp = 0, s;
        cin >> n >> m;
        a.clear();
        a.resize(n + 1);
        check.clear();
        check.resize(n + 1, 1);
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        
        for (int i = 1; i <= n; i++)
        {
            check.clear();
            check.resize(n + 1, 1);
            s = 0;
            check[i] = 0;
            for (int j = 1; j <= n; j++)
            {
                if (check[j])
                {
                    s++;
                    check[j] = 0;
                    bfs(j);
                }
            }
            cout << s << "\n";
        }
        cout << "\n";
    
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    if (fopen(TASK ".inp", "r")) freopen(TASK ".inp", "r", stdin);
    
    int Test = 1;
    // cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}
