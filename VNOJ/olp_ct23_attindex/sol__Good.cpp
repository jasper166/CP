#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/priority_queue.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
/* ordered_set notes:
    .order_of_key(k): Number of items strictly smaller than k
    .find_by_order(k): k-th element in a set
*/
#define X first
#define Y second
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
#ifdef cychien
#define DE(...) do {\
	fprintf(stderr, "%s - %d : (%s) = ", __PRETTY_FUNCTION__, __LINE__, #__VA_ARGS__);\
    _DO(__VA_ARGS__);\
}while(0) 
template<typename I> void _DO(I&&x) {cerr << x << '\n';}
template<typename I, typename ...T> void _DO(I&&x,T&&...tail) {cerr << x << ", "; _DO(tail...);}
template<class T> void debug(T l, T r) { while (l != r) cerr << *l << " \n"[next(l)==r], ++l; }
#define IOS
#else
#define DE(...) 0
#define debug(...) 0  
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#endif
#define W(v) {for(auto it = (v).begin(); it != (v).end(); it++)cout << *it << " \n"[next(it) == (v).end()];}
#define pb emplace_back
#define mp make_pair
#define rsz resize
#define SZ(x) (ll)x.size()
#define AI(x) (x).begin(),(x).end()
#define SORT(x) sort(AI(x))
template<class T> bool chmin(T &a, T b) { return b < a && (a = b, true); }
template<class T> bool chmax(T &a, T b) { return a < b && (a = b, true); }
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
const int NF = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int Rand(){
    return uniform_int_distribution<int>(INT_MIN, INT_MAX)(rng);
}
/*
#include <atcoder/all>
using namespace atcoder;
using mint = modint1000000007;
using mint = modint998244353;
*/
const int MAXn = 100000, K = 317;
int P, n;
int a[MAXn + 5];
int pre[MAXn + 5];
ll pre2[MAXn + 5], pre3[MAXn + 5];
ll ans[MAXn + 5];
int cnt[MAXn + 5];
int main() {
    IOS;
    cin >> P;
    string s; cin >> s;
    n = SZ(s);
    for (int i = 0; i < n; i++){
        a[i + 1] = s[i] - '0';
    }

    int q; cin >> q;
    vector<array<int, 3>> queries(q);
    for (int i = 0; i < q; i++){
        int l, r; cin >> l >> r;
        queries[i] = array<int, 3>{l, r, i};
    }

    if (P == 2 || P == 5){
        for (int i = 1; i <= n; i++){
            pre2[i] = pre2[i - 1] + 1ll * i * (a[i] % P == 0);
            pre3[i] = pre3[i - 1] + (a[i] % P == 0);
        }

        for (auto [l, r, _] : queries){
            cout << (pre2[r] - pre2[l - 1]) - 1ll * (l - 1) * (pre3[r] - pre3[l - 1]) << '\n';
        }
        exit(0);
    }
    for (auto& [l, r, _] : queries) ++r;
    sort(AI(queries), [&](auto a, auto b){
        return (a[0] / K != b[0] / K) ? (a[0] / K < b[0] / K) : (a[1] < b[1]);
    });
    vector<int> discretization(1, 0);
    DE(n);
    for (int i = n, pw = 1; i >= 1; --i, pw = 1ll * pw * 10 % P){
        DE(i);
        pre[i] = (pre[i + 1] + 1ll * pw * a[i]) % P;
        discretization.pb(pre[i]);
    }
    sort(AI(discretization));
    discretization.resize(unique(AI(discretization)) - discretization.begin());
    for (int i = 1; i <= n; i++){
        pre[i] = lower_bound(AI(discretization), pre[i]) - discretization.begin();
    }

    ll val = 0;
    auto add = [&](int x){
        val -= 1ll * cnt[pre[x]] * (cnt[pre[x]] - 1) / 2;
        cnt[pre[x]]++;
        val += 1ll * cnt[pre[x]] * (cnt[pre[x]] - 1) / 2;
    };

    auto sub = [&](int x){
        val -= 1ll * cnt[pre[x]] * (cnt[pre[x]] - 1) / 2;
        cnt[pre[x]]--;
        val += 1ll * cnt[pre[x]] * (cnt[pre[x]] - 1) / 2;
    };

    for (int curl = 1, curr = 1; auto [l, r, idx] : queries){
        while (curl > l) add(--curl);
        while (curr < r) add(curr++);
        while (curl < l) sub(curl++);
        while (curr > r) sub(--curr);
        ans[idx] = val + cnt[pre[r]];
    }

    for (int i = 0; i < q; i++){
        cout << ans[i] << '\n';
    }
    return 0;
}

