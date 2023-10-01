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
void run_case(){
    cin >> n;
    if (n == 1) {
        cout << "0\n";
        return;
    }
    queue <int> q;
    unordered_map <int, int> d;
    q.emplace(n);
    d[n] = 0;
    while (!q.empty()) {
        auto x = q.front();
        q.pop();
        if (x == 1) {
            cout << d[x] << "\n";
            return;
        }
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                int ni = x / i;
                if (d.find(ni) == d.end()) {
                    if (ni == 1) {
                        cout << d[i] + 1 << "\n";
                        return;
                    }
                    d[ni] = d[x] + 1;
                    q.emplace(ni);
                } 
            }
        }
        
        if (d.find(x - 1) == d.end()){
            if (x == 2) {
                cout << d[2] + 1 << "\n";
                return;
            }
            d[x - 1] = d[x] + 1;
            q.emplace(x - 1);
        }
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
