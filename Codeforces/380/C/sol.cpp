#include "bits/stdc++.h"
// @Jasper


using namespace std;
using ll = long long;
using pii = pair < int, int >;
using pll = pair < ll, ll >;

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
#else
#define debug(...) 42
#define debugArr(...) 42
#endif

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

int ans[MAX], pos[MAX];
int m, n;
string s;
int fenwick[MAX];

void add(int x, int val){
    for (; x < MAX; x += (x & -x)) fenwick[x] += val;
}

int get(int x){
    int answer = 0;
    for (; x; x -= (x & -x)) answer += fenwick[x];
    return answer;
}

struct query{
    int l, r, id;
    bool operator< (const query x){
        return (this->r < x.r || (this->r == x.r && this->l < x.l));
    }
};

query q[MAX];

void prepare(){
    n = s.size();
    memset(pos, -1, sizeof(pos));
    memset(fenwick, 0, sizeof(fenwick));
    stack <int> st;
    s = '$' + s;
    for (int i = 1; i <= n; i++){
        if (s[i] == '(') st.push(i);
        else {
            if (!st.empty()){
                pos[i] = st.top();
                st.pop();
            }
        }
    }
}

void run_case(){
    cin >> s >> m;
    prepare();
    for (int i = 1; i <= m; i++){
        cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }

    sort(q + 1, q + 1 + m)
    int j = 1;
    for (int i = 1; i <= m; i++){
        for (; j <= n && j <= q[i].r; j++){
            if (pos[j] == -1) continue;
            add(pos[j], 1);
        }
        ans[q[i].id] = (get(q[i].r) - get(q[i].l - 1)) * 2;
    }

    for (int i = 1; i <= m; i++)
        cout << ans[i] << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
//    cin >> Test;
    FOR(i, 1, Test){
        run_case();
    }
}


