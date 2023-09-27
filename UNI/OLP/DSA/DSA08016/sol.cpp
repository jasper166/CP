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
const int MAX = 1e6 + 5;

string des = "1238004765";

int l[] = {0, 1, 5, 8, 7, 3};
int r[] = {1, 2, 6, 9, 8, 4};
int ans = INF;

string get (string x, int op) {
    string y = x;
    if (op == 1) {
        for (int i = 0; i < 6; i++) 
            y[l[i]] = x[l[(i + 5) % 6]];
    }
    else if (op == 2) {
         for (int i = 0; i < 6; i++) 
            y[r[i]] = x[r[(i + 5) % 6]];
    }
    else if (op == 3) {
         for (int i = 0; i < 6; i++) 
            y[l[i]] = x[l[(i + 1) % 6]];
    }
    else {
         for (int i = 0; i < 6; i++) 
            y[r[i]] = x[r[(i + 1) % 6]];
    }
    return y;
}

unordered_map <string, int> mp[2];

void Rotate (string x, int i){
    queue <pair <string, int>> q;
    q.emplace(x, 0);
    mp[i][x] = 1;
    while (!q.empty()) {
        auto [s, d] = q.front();
        q.pop();
        if (d > 12) continue;
        
        if (i && mp[i ^ 1][s]) 
            ans = min(ans, mp[i ^ 1][s] + d);

        string sl = get(s, 1 + 2 * i);
        string sr = get(s, 2 + 2 * i);
        if (mp[i][sl] == 0) {
            mp[i][sl] = d + 1;
            q.emplace(sl, d + 1);
        }
        if (mp[i][sr] == 0) {
            mp[i][sr] = d + 1;
            q.emplace(sr, d + 1);
        }
    }
}

void run_case(){
    string s;
    mp[0].clear();
    mp[1].clear();
    ans = INF;

    for (int i = 1; i <= 10; i++){
        int x; cin >> x;
        s += (char) (x + '0');
    }
    Rotate(s, 0);
    Rotate(des, 1);
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

