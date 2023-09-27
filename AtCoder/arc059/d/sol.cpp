#include "bits/stdc++.h"
// @Jasper
using namespace std;
using ll = long long;
using pii = pair < int, int >;

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
#else
#define debug(...) 166
#define debugArr(...) 166
#endif


const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

bool isUnbalanced(string x) {
    map <char, int> cnt;
    for (auto c : x) cnt[c]++;
    int maxF = 0;
    for (auto [d, c] : cnt) {
        maxF = max(maxF, c);
    }
    return (x.size() >= 2 && maxF > (x.size() / 2));
}

void run_case() {
    string s;
    cin >> s;
    int n = s.size();
    // debug(isUnbalanced("nee"));
    for (int i = 0; i < n; i++) {
        for (int j = 2; j <= 3; j++) {
            if (i + j > n) continue;
            string x = s.substr(i, j);
            // debug(x);
            if (isUnbalanced(x)) {
                debug(x);
                cout << (i + 1) << " " << (i + j) << "\n";
                return;
            }
        }
    }
    cout << "-1 -1\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
