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

vector <string> res;
vector <int> cur;
int n, k;
int a[22];

void helper (int sum, int last) {
    if (sum == 0) {
        string s = "{";
        for (int i = 0; i < (int) cur.size() - 1; i++)  s += to_string(cur[i]) + " ";
        s += to_string(cur.back()) + "}";
        res.push_back(s);
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] >= last && sum >= a[i]) {
            cur.push_back(a[i]);
            helper (sum - a[i], a[i]);  
            cur.pop_back();
        }
    }
}

void run_case(){
    res.clear();


    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    helper(k, 1);

    if (res.empty()) {
        cout << "-1\n"; 
        return;
    }

    cout << res.size() << " ";
    for (int i = 0; i  < res.size(); i++) {
        cout << res[i] << " ";
    } 
    cout << "\n";
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

