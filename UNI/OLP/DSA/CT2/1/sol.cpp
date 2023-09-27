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
#define int long long
const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 5e2 + 5;

int n;
vector <int> vec;
vector <string> res;
void func (int i, int sum) {
	if (sum == 0) {
        // for (auto x : vec) cout << x << " ";
        // cout << "\n";
        string s;
        s += "(";
        for (int i = vec.size() - 1; i; i--)
            s += to_string(vec[i]) + " ";
        s += to_string(vec[0]) + ")";
        res.push_back(s);
        // cout << s << "\n";
    }
	for (int j = i; j <= n; j++) {
		if (sum >= j) {
            vec.push_back(j);
            func(j, sum - j);
		    vec.pop_back();
        }
	}
}

void run_case(){
    cin >> n;
    res.clear();
    func(1, n);
    
    res.resize(unique(all(res)) - res.begin());
    sort(all(res));
    cout << res.size() << "\n";
    reverse(all(res));
    map <string, int> mp;
    mp["(10)"] = 1;
    if (n == 10) 
        cout << "(10) ";
    for (auto x : res) 
        if (!mp[x])
            cout << x << " ";
    cout << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    if (fopen(TASK ".inp", "r")) freopen(TASK ".inp", "r", stdin);
    
    int Test = 1;
    cin >> Test;
    FOR(i, 1, Test){
        // cout << "Test " << i << ": ";
        run_case();
    }
}

