#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;
using pii = pair < int, int >;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

#define int long long
struct Line {
    ll a, b;
    Line (ll _a, ll _b) {
        a = _a; b = _b;
    }
    ll cal(ll x) {
        return (a * x + b);
    } 

};
bool useless (const Line& y1, const Line& y2, const Line& y3) {
    return (y2.b - y1.b) * (y1.a - y3.a) >= (y3.b - y1.b) * (y1.a - y2.a);
}

int n, c;
int a[MAX];
void run_case() {
    cin >> n >> c;

    ll bestF = 0;
    deque <Line> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        int x = a[i];
        Line nLine(-2ll * x, x * x + bestF);
        while (q.size() >= 2 && useless(q[q.size() - 2], q[q.size() - 1], nLine))
            q.pop_back();
        q.push_back(nLine);
        while (q.size() >= 2 && q[0].cal(x) >= q[1].cal(x)) 
            q.pop_front();
        bestF = q[0].cal(x) + x * x + c;
    }
    cout << bestF << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}


