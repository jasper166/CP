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
const int MAX = 2e3 + 5;

int n;
vector <int> match[MAX];
int cnt[MAX], assigned[MAX], C;
pii a[MAX], b[MAX];
int A, B;

bool matchChecking(int u){
    if(cnt[u] == C)
        return 0;
    cnt[u] = C;
    for(auto v : match[u]){
        if(assigned[v] == 0 || matchChecking(assigned[v])){
            assigned[v] = u;
            return 1;
        }
    }
    return 0;
}


void run_case(){
    A = B = 0;
    // C = 0; 
    for (int i = 1; i <= n; i++){
        match[i].clear();
        assigned[i] = 0;
    }

    for (int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        if ((x + y) & 1)
            b[++B] = make_pair(x, y);
        else 
            a[++A] = make_pair(x, y);
    }
    for (int i = 1; i <= A; i++)
        for (int j = 1; j <= B; j++)
            if (abs(a[i].fi - b[j].fi) + abs(a[i].se - b[j].se) < 2)
                match[i].push_back(j);
    int ans = 0;
    for (int i = 1; i <= A; i++){
        C++;
        if (matchChecking(i))
            ans++;
    }
            
    cout << A + B - ans << "\n";
    
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    while (cin >> n)
        run_case();
}