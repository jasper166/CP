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
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#ifdef LOCAL
#include "debug.h"
#define TASK "INP"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e3 + 5;

int n, m, k;
int f[MAX][MAX], a[MAX][MAX];
//int res[5];

int get(int a, int b, int A, int B){
    return (f[A][B] + f[a - 1][b - 1] - f[a - 1][B] - f[A][b - 1]);
}

void update(int i, int j){
    f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + a[i][j];
}

void run_case(){
    cin >> n >> m >> k;

    for (int r = 0; r < n; r++){
        string s; cin >> s;
        for (int c = 0; c < m; c++){
            a[r][c] = (s[c] == '1');
            a[r][c] += (c? a[r][c - 1] : 0);
        }
    }
    unordered_map <int, int> mp;
    int ans = 0;
    for (int cf = 0; cf < m; cf++){
        for (int cs = cf; cs < m; cs++){
            mp = {{0, 1}};
            int cur = 0;
            for (int r = 0; r < n; r++){
                cur += a[r][cs] - (cf? a[r][cf - 1] : 0);
                ans += mp[cur - k];
                mp[cur]++;
            }
        }
    }
    cout << ans << "\n";

}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    if (fopen(TASK ".inp", "r")) freopen(TASK ".inp", "r", stdin);
    
    int Test = 1;
    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}

