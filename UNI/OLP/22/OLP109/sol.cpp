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
#define TASK "OLP109"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

string s;
int a[MAX];
struct node{
    int sum;
    int cnt[3];
    void clr(){
        memset(cnt, 0, sizeof(cnt));
    }
} st[4 * MAX];

node merge(node x, node y){
    node ans;
    ans.clr();
    ans.sum = (x.sum + y.sum) % 3;
    if (x.sum == 2){
        ans.cnt[0] = x.cnt[0] + y.cnt[1];
        ans.cnt[1] = x.cnt[1] + y.cnt[2];
        ans.cnt[2] = x.cnt[2] + y.cnt[0];
    }
    else if (x.sum == 1){
        ans.cnt[0] = x.cnt[0] + y.cnt[2];
        ans.cnt[1] = x.cnt[1] + y.cnt[0];
        ans.cnt[2] = x.cnt[2] + y.cnt[1];
    }
    else {
        for (int i = 0; i < 3; i++)
            ans.cnt[i] = x.cnt[i] + y.cnt[i];
    }
    return ans;
}

void build(int l, int r, int N){
    if (l == r){
        st[N].sum = a[l] % 3;
        st[N].clr();
        st[N].cnt[st[N].sum]++;
        return;
    }
    int m = (l + r) >> 1;
    build(l, m, N * 2);
    build(m + 1, r, N * 2 + 1);
    st[N] = merge(st[N * 2], st[N * 2 + 1]);
}

void update(int l, int r, int N, int idx, int val){
    if (l == r){
        st[N].sum = val % 3;
        st[N].clr();
        st[N].cnt[st[N].sum]++;
        return;
    }
    int m = (l + r) >> 1;
    if (idx <= m)
        update(l, m, N * 2, idx, val);
    else
        update(m + 1, r, N * 2 + 1, idx, val);
    st[N] = merge(st[N * 2], st[N * 2 + 1]);
}

node query(int l, int r, int N, int L, int R){
    if (L <= l && r <= R)
        return st[N];
    int m = (l + r) >> 1;
    if (R <= m)
        return query(l, m, N * 2, L, R);
    else if (L > m)
        return query(m + 1, r, N * 2 + 1, L, R);
    else{
        node x = query(l, m, N * 2, L, m);
        node y = query(m + 1, r, N * 2 + 1, m + 1, R);
        return merge(x, y);
    }
}

int n, q;

void run_case(){
    cin >> n >> q >> s;
    s = '$' + s;
    for (int i = 1; i <= n; i++) a[i] = s[i] - '0';
   /* 
    cout << s << "\n";
    FOR(i, 1, n) cout << a[i] << " \n"[i == n];
*/
    build(1, n, 1);

    for (int i = 1; i <= q; i++){
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 1)
            update(1, n, 1, u, v);
        else{
            node ret = query(1, n, 1, u, v);
            ll c0 = ret.cnt[0];
            ll c1 = ret.cnt[1];
            ll c2 = ret.cnt[2];

            ll ans = (c0 * (c0 + 1) + c1 * (c1 - 1) + c2 * (c2 - 1)) / 2;
            
            cout << ans << "\n";
        }
    }
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    
    if (fopen(TASK ".inp", "r"))
        freopen(TASK ".inp", "r", stdin);
    
    int Test = 1;
//    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}




