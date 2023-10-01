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
const int MAX = 1e4 + 5;

int p[MAX], sz[MAX];
int q, op, u, v;

int get(int a){
    return (a == p[a]? a : p[a] = get(p[a]));
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if (a != b){
        if (sz[a] < sz[b]) swap(a, b);
        sz[a] += b;
        p[b] = a;
    }
}

void run_case(){
    cin >> q;
    REP(i, MAX) p[i] = i, sz[i] = 1;
    
    while (q--){
        cin >> u >> v >> op;
        if (op == 1)
           unite(u, v);
        else 
           cout << (get(u) == get(v)) << "\n";
    }

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



