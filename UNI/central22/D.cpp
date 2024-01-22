#include "bits/stdc++.h"
// @Jasper x Powder
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
#define el "\n"
#define LL long long
#define bit(a,b) ((a >> b)&1)
#define countBit(a) __builtin_popcount(a)
#define sum(l,r,val) accumulate(l,r,val)
#define len(s) (int)s.size()

#ifdef LOCAL
#include "debug.h"
#define TASK "61E"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int n,q;
int a[MAX], b[MAX];
int sz;
vector <int> ans;
int root[MAX];
struct Node{
    int ls, rs, cnt;
}node[MAX * 20];


void update(int &n,int pre,int l, int r,int pos){
    n = ++sz;
    node[n] = node[pre];
    if(l == r  && l == pos) {
        node[n].cnt++;
        node[n].ls = node[n].rs = 0;
        return;
    }
    int mid = (l + r) >> 1;
    if(pos <= mid) 
        update(node[n].ls, node[pre].ls, l, mid, pos);
    else 
        update(node[n].rs, node[pre].rs, mid + 1, r, pos);
    node[n].cnt = node[node[n].ls].cnt + node[node[n].rs].cnt;
}
 
int query(int r1, int r2, int l, int r, int val){
    if(l == r) 
        return l;
    int cur = node[node[r1].ls].cnt - node[node[r2].ls].cnt;
    int mid = (l + r) >> 1;
    if(cur >= val) 
        return query(node[r1].ls, node[r2].ls, l, mid, val);
    else 
        return query(node[r1].rs, node[r2].rs, mid + 1, r, val - cur);
}

void run_case(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        ans.push_back(a[i]);
    }

    sort(all(ans));
    for(int i = 1; i <= n; i++) 
        a[i] = lower_bound(all(ans), a[i]) - ans.begin() + 1;

    int S = (int) ans.size();
    update(root[1], 0, 1, S, a[1]); 
    for(int i = 2; i <= n; i++){
        update(root[i], root[i - 1], 1, S, a[i]);
    }
     
    while(q--) {
        int l, r, x;
        cin >> l >> r;
        x = ((r - l + 1) + 1) / 2;
        int k = query(root[r], root[l - 1], 1, S, x);
        cout << ans[k - 1] << "\n";
    }
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
    // cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}
