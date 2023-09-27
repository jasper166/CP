#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second
#ifdef JASPER2
#include "debug.h"
#else
#define debug(...) 166
#endif

#define int long long
using pii = pair < int, int >;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

int n, k;
int a[N];
vector <int> b[N];
int c[N], res[N];
set <int> st;
void run_case() {
    cin >> n >> k;
    st.clear();
    REP(i, n) {
        cin >> a[i];
        b[a[i]].push_back(i); c[i] = 0;
        st.insert(a[i]);
    }
    FOR(i, 1, k) res[i] = 0;
    int l = 0, r = n - 1;
    for (auto x : st) {
        while (l <= r && c[l] == 1) ++l;
        while (l <= r && c[r] == 1) --r;
        if (l <= r) {
            res[x] = r - l + 1;
            for (int j : b[x]) c[j]++;
            b[x].clear();  
        }
        else
            res[x] = 0;
    }
    FOR(i, 1, k) cout << (res[i] << 1) << " \n"[i == k];
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    #ifdef JASPER2
        freopen("in1", "r", stdin);
    #endif

    int Test = 1;
    cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
