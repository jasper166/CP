#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;

#define fi first
#define se second
#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

#define int long long
using pii = pair < int, int >;
const ll INF = 1e18;
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

struct Fenwick {
    vector <int> f;
    Fenwick() : f(N + 5, 0) {};
    void upd(int x, int val) {
        for (; x < N; x += x & -x)
            f[x] += val;
    }
    int qry(int x) {
        int ans = 0;
        for (; x; x -= x & -x)
            ans += f[x];
        return ans;
    }
};

int n, x;
int a[N * 2], id[N * 2];
void run_case() {
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        id[i] = i;
        if (a[i] < id[i]) a[i] += n;
    }

    for (int i = n + 1; i <= 2 * n; ++i) {
        a[i] = a[i - n];
        id[i] = i;
        if (a[i] < id[i]) a[i] += n;
    }

        ordered_set <int> st;
    for (int i = 2 * n; i >= 1; --i) {
        int x = st.ordered_set(a[i]);
        int y = a[i] - n;
        if (y < 0) y += n;
        ans[y] = max(0ll, a[i] - id[i] - x);
        st.insert(a[i]);
    }

    for (int i = 1; i <= n; ++i)
        cout << ans[i] << " \n"[i == n];
}



signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}
