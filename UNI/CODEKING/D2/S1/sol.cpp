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
const int MAX = 5e4 + 5;

int n;
int r1[MAX], r2[MAX], pos[2 * MAX];
bool vis[MAX];
vector <int> edges[MAX];
int ans, total, component;

void dfs(int u){
    for (int v : edges[u]){
        if (!vis[v]){
            vis[v] = 1;
            ++total;
            bool check = 1;
            if (r1[v] != r1[u] && r2[v] != r2[u]) check = 0;
            if (check){
          	    ++component;
                swap(r1[v], r2[v]);
            }
            dfs(v); 
        } 	
    }
}

void run_case(){
    cin >> n;

    for (int i = 1; i <= n; ++i) cin >> r1[i];
    for (int i = 1; i <= n; ++i) cin >> r2[i];
    for (int i = 1; i <= n; ++i){
        if (pos[r1[i]]){
            edges[i].push_back(pos[r1[i]]);
            edges[pos[r1[i]]].push_back(i);
        }
        if (pos[r2[i]]){
            edges[i].push_back(pos[r2[i]]);
            edges[pos[r2[i]]].push_back(i);
        }
        pos[r1[i]] = pos[r2[i]] = i;
    }

    for (int i = 1; i <= n; i++){
        set <int> tmp;
        for (int u : edges[i]) tmp.insert(u);
        edges[i].assign(all(tmp));
    }

    for (int i = 1; i <= n; ++i){
        total = component = 0;
		dfs(i);
		ans += min(component, total - component);
    }
    cout << ans << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
    // cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}
// Codename : Jasper the Otter




