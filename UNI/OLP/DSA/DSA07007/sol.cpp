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

void trans (string& s) {
    int n = s.size();
    vector <char> a, b;

    for (int i = 0; i < n; i++) {
       debug(s[i]);
        if (isalpha(s[i]))
            a.push_back(s[i]);
        else if (s[i] == '-' || s[i] == '+') {
            char x = s[i];
            if (!b.empty() && b.back() == '-')
                x = (x == '+')? '-' : '+';           
            a.push_back(x);
        }
        else if (s[i] == '(') {
            if (!a.empty()) {
                b.push_back(a.back());
            }
        }
        else {
            if (!b.empty())
                b.pop_back();
        }
    }
    s.clear();
    for (auto x : a)
        s += x;  
}

void run_case(){
    string a, b;
    cin >> a >> b;
    debug(a);
    trans(a);
    trans(b);
    cout << (a == b? "YES\n" : "NO\n");
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    if (fopen(TASK ".inp", "r")) freopen(TASK ".inp", "r", stdin);
    
    int Test = 1;
    cin >> Test;
    // cin.ignore();
    FOR(i, 1, Test){

        run_case();
    }
}

