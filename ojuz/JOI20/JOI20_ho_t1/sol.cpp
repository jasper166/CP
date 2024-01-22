#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#define fi first
#define se second
#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

using pii = pair < int, int >;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;

int n;
pair <int, int> a[N];
int b[N];
int ans[N];

void run_case() {

    cin >> n;
    for (int i = 1; i <= n + 1; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    for (int i = 1; i <= n; ++i) cin >> b[i];

    sort(a + 1, a + 2 + n);
    sort(b + 1, b + 1 + n);

    set <int> st;
    for (int i = 1; i <= n; ++i) {
        st.insert(max(0, a[i].first - b[i]));
    }

//    debug(st);
    ans[a[n + 1].second] = *st.rbegin();

    for (int i = n; i >= 1; --i) {
        st.erase(max(0, a[i].first - b[i]));
        st.insert(max(0, a[i + 1].first - b[i]));
        ans[a[i].second] = *st.rbegin();
    }
    
    for (int i = 1; i <= n + 1; ++i) 
        cout << ans[i] << " \n"[i == n + 1];
}

/*
    3 4 6 7
    2 4 6

    SegTree 2D
    TPSLT
*/

signed main() {
    cin.tie(0) -> sync_with_stdio(0);

    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
    #endif
    
    int Test = 1;
    //cin >> Test;
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}


