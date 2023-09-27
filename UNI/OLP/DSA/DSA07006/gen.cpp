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

char c[] = {'-', '+', '/', '*'};
void run_case(){
    int n = uid(1, 10);
    int m = uid(1, 5);

    vector <int> cnt(n + 1, 0);
    vector <pii> b(m + 1); 
    for (int i = 1; i <= m; i++) {
        int f = uid(1, m - 1);
        int s = uid(f + 1, m);
        b[i] = {f, s};

    }
    if (n % 2 == 0)
        n++;
    string s;
    for (int i = 1; i <= n; i += 2) {
        int num = uid(1, 9);
            s += to_string(num);
            if (s.size() >= n)
                break;
            char op = c[uid(0, 3)];
            s += op;
        
    } 
    s = "$" + s;
    //  ;
    for (int i = 1; i <= m; i++) {
        int F = b[i].fi * 2 - 1;
        int S = b[i].se * 2 - 1;
        string x = s.substr(1, F - 1) + "(" + s.substr(F, S) + ")" + s.substr(S + 1);
         // + "(" + s.sub
        s = x;
    }
    int l = 0;
    int r = 0;
    for (auto x : s) {
        if (x == '(') l++;
        if (x == ')') r++; 
    }
    while (l < r) {
        s = "(" + s;
        l++;
    }
    while (l > r) {
        s = s + ")";
        r++;
    }
    cout << s << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    if (fopen(TASK ".inp", "r")) freopen(TASK ".inp", "r", stdin);
    
    int Test = 1;
    //cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}

