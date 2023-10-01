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

#ifdef LOCAL
#include "debug.h"
#define TASK "OLP22C"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

struct disk{
    int a, b;
    ll h;

    bool operator < (const disk &other) const{
        if (b != other.b)
            return b < other.b;
        return a < other.a;
    }
};

disk a[MAX];
int n;

void run_case(){
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].a >> a[i].b >> a[i].h;
    sort(a + 1, a + 1 + n);
    stack <disk> st;
    ll ans = 0;
    for (int i = n; i >= 1; i--){
        while (!st.empty() && st.top().a >= a[i].b)
            st.pop();
        if (st.empty()){
            ans = max(ans, a[i].h);
            st.push(a[i]);
        }
        else {
            ll cur_height = st.top().h;
            ans = max(ans, cur_height + a[i].h);
            st.push({a[i].a, a[i].b, cur_height + a[i].h});
        }
    }
    cout << ans << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    if (fopen(TASK ".inp", "r"))
        freopen(TASK ".inp", "r", stdin);
    
    int Test = 1;
   // cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}

