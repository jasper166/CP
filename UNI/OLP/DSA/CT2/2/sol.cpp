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
#define debug(...) 42
#define debugArr(...) 42
#endif
#define int long long
const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 32;

int a[1001], ok, n;
void helper()
{
    int i = n;
    while (i >= 1 && a[i] == n)
    {
        --i;
    }
    if (i == 0)
        ok = 0;
    else
    {
        a[i]++;
        for (int j = i + 1; j <= n; j++)
        {
            a[j] = 1;
        }
    }
}

void run_case() {
    cin >> n;
    string s = "";
    for (int i = 1; i <= n; i++)
    {
        s += 'A' + i - 1;
    }
    vector <string> v1, v2;
    do
    {
        v1.push_back(s);
    } while (next_permutation(s.begin(), s.end()));
    ok = 1;
    for (int i = 1; i <= n; i++)
    {
        a[i] = 1;
    }
    while (ok)
    {
        string res = "";
        for (int i = 1; i <= n; i++)
        {
            res += to_string(a[i]);
        }
        v2.push_back(res);
        helper();
    }
    for (auto x : v1)
    {
        for (auto y : v2)
        {
            cout << x << y << "\n";
        }
    }

}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    // cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
