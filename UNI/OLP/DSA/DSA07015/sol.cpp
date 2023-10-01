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

string s;
vector <ll> num;
vector <char> ops;

ll process () {
    ll a = num.back(); num.pop_back();
    if (num.empty())
        return a;
    ll b = num.back(); num.pop_back();
    char x = ops.back(); ops.pop_back();
    if (x == '+')
        return b + a;
    else if (x == '-')
        return b - a;
    else if (x == '*')
        return b * a;
    else 
        return b / a;
}

int pre (char x) {
    if (x == '*' || x == '/')
        return 2;
    else if (x == '+' || x == '-')
        return 1;
    else
        return 0;

}
// pair <char, int> pre[] = {{'+', }} 

void run_case(){
    cin >> s;
    int n = s.size();
    s = "$" + s;
    ll res = 0;
    // debug(n, s);
    for (int i = 1; i <= n; i++) {
        if (isdigit(s[i])) {
            int x = 0;

            for (; i <= n && isdigit(s[i]); i++) {
                x = x * 10 + (s[i] - '0');
            }
            --i;
            num.push_back(x);
        }
        else if (s[i] == '(') {
            ops.push_back(s[i]);
        }
        else if (s[i] == ')') {
            while (ops.back() != '(') {
                res = process();
                num.push_back(res);
            }
            ops.pop_back();
        }
        else {
            while (!ops.empty() && pre(s[i]) <= pre(ops.back())) {
                res = process();
                num.push_back(res);
            }
            ops.push_back(s[i]);
        } 

    }
    // debug(num, ops);
    while (!ops.empty()) {
        res = process();
        num.push_back(res);
    }
    cout << num.back() << "\n";
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

