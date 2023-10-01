#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef long long ll;
const int MAX = 2e5 + 10;

vector <int> adj[MAX];
vector <pair<ll, ll>> remain[MAX];
set <pair<ll, ll>> m;
int n, sz[MAX], par[MAX], val[MAX];

int get(int x) {
    return (par[x] == x)? x : par[x] = get(par[x]);
}

int size(int x) {
    return sz[get(x)];
}

void unite(int x, int y) {
    x = get(x), y = get(y);
    if (x == y)
        return;

    if (sz[x] < sz[y]) swap(x, y);
    for (auto t : remain[y])
        m.insert(t);

    remain[y].clear();

    sz[x] += sz[y];
    par[y] = x;
}

void process(int u) {
    m.clear();

    for (auto x : adj[u]) {
        if (size(x) > 1)
            unite(x, u);
        else
            m.insert({val[x], x});
    }

    while (m.size()) {
        auto t = *m.begin();

        if (size(u) >= t.f) {
            unite(u, t.s);
            for (auto x : adj[t.s]) {
                if (size(x) > 1)
                    unite(x, u);
                else
                    m.insert({val[x], x});
            }
        } 
        else {
            for (auto x : m)
                remain[get(u)].push_back(x);
        } 

        m.erase(t);
    }   
}

void clear() {
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        par[i] = i;
        sz[i] = 1;
        remain[i].clear();
    }
}

void solve() {
    int m;
    cin >> n >> m;
    clear();

    for (int i = 1; i <= n; i++) 
        cin >> val[i];

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }


    for (int i = 1; i <= n; i++) {
        if (!val[i] && size(i) == 1)
            process(i);
    }

    cout << (size(1) >= n? "YES\n" : "NO\n");
}
 
int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }
}


// f[1][i] = 1
// f[2][i] = sigma(f[1][j])