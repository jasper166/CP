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
vector <bool> vis;
string s;
vector <pii> p;
vector <int> b;
vector <int> choose;

void get (int N, int K, int i) {
    if (choose.size() == K) {
        string t = s;
        // debug(choose);
        for (int i = 0; i < K; i++) {
            auto [x, y] = p[choose[i]];
            t[x] = t[y] = '?';
        }
        string ret;
        for (int i = 0; i < t.size(); i++) {
            if (t[i] != '?')
                ret += t[i];
        }
        res.emplace_back(ret);
        return;
    }
    if (i >= N)
        return;

    for (int j = i; j < N; j++) {
        choose.push_back(j);
        get(N, K, j + 1);
        choose.pop_back();
    }
}

void solve (int N, int K) {
    choose.clear();
    get(N, K, 0);
}

void run_case(){

    cin >> s;
    int n = s.size();
    
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            b.push_back(i);
        }
        else if (s[i] == ')') {
            p.emplace_back(b.back(), i);
            b.pop_back();
        }
    }
    int N = p.size();
    vis.resize(N);
    for (int i = 1; i <= N; i++) {
        solve(N, i);
    }
    sort(all(res));
    res.resize(unique(res.begin(), res.end()) - res.begin());
//    debug(res.size());
    for (auto x : res) cout << x << "\n";
    // debug(p);

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

