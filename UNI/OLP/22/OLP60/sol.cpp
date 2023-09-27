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
#define TASK "OLp60"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

const int BASE = 31;
using ull = unsigned long long;

ull pw[MAX], h[MAX];
int n, k;
string s;

void prepare(){
    pw[0] = 1;
    for (int i = 1; i < MAX; i++)
        pw[i] = pw[i - 1] * 1LL * BASE;
}

ull get(int i, int j){
    if (i == 0)
        return h[j];
    return (h[j] - h[i - 1] * pw[j - i + 1]);            
}

bool ok(int m){
    //map <ull, int> mp;
    vector <ull> st;
    for (int i = 0; i <= n - m; i++){
        ull cur = get(i, i + m - 1);
        st.push_back(cur);
    }
    sort(all(st));
    for (int i = 0; i < st.size(); i++){
        int cnt = 1;
        while (st[i] == st[i + 1]){
            cnt++;
            i++;
        }
        if (cnt >= k) return 1;
    }
    return 0;
}

void run_case(){
    cin >> n >> k >> s;

    h[0] = s[0] - 'a' + 1;
    for (int i = 1; i < n; i++)
       h[i] = h[i - 1] * BASE * 1LL + s[i] - 'a' + 1;

    int l = 1, r = n, ans = 0;
    while (l <= r){
        int m = (l + r) >> 1;
        if (ok(m)){
            ans = m;
            l = m + 1;
        }
        else 
            r = m - 1;
    }
    cout << ans << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    if (fopen(TASK ".inp", "r"))
        freopen(TASK ".inp", "r", stdin);
   
    prepare();

    int Test = 1;
    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}

