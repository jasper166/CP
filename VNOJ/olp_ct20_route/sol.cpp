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
#define int long long
const ll LINF = 1e18 + 5;
const int INF = 1e18;
const int MOD = 1e9 + 7;
const int MAX = 1e3 + 5;

int n, m;
int a[MAX][MAX];
int f2[MAX][MAX], f5[MAX][MAX];
int p2[MAX][MAX], p5[MAX][MAX];
string path;

int get(int p, int x){
    int ans = 0;
    if (x == 0) return INF;
   // debug(x, p);
    while (x % p == 0){
        ans++;
        x /= p;
    }
    return ans;
}

string trace(int p){
    string ans = "";
    if (p == 2){
        int x = n;
        int y = m;
        //pii st = make_pair(1, 1);
        while (x > 1 || y > 1){
            if (f2[x - 1][y] < f2[x][y - 1]){
                ans += 'D';
                x--;
            }
            else {
                ans += 'L';
                y--;
            }
        }
    }
    else {
        int x = n;
        int y = m;
        while (x > 1 || y > 1){
            if (f5[x - 1][y] < f5[x][y - 1]){
                ans += 'D';
                x--;
            }
            else {
                ans += 'L';
                y--;
            }
        }
    }
    reverse(all(ans));
    return ans;
}

void run_case(){
    cin >> n >> m;
    pair <ll, ll> pos = make_pair(-INF, INF);
    memset(f2, 0x3f3f3f3f, sizeof(f2));
    memset(f5, 0x3f3f3f3f, sizeof(f5));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
            if (a[i][j] == 0 && pos.se != 1){
                if (i > pos.fi || (i == pos.fi && j < pos.se))
                    pos = make_pair(i, j);
               
            }
            p2[i][j] = get(2, a[i][j]);
            p5[i][j] = get(5, a[i][j]);
        }
    }
    f2[1][1] = p2[1][1];
    f5[1][1] = p5[1][1];
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (i == 1 && j == 1) continue;
            f2[i][j] = min(f2[i - 1][j], f2[i][j - 1]) + p2[i][j];
            f5[i][j] = min(f5[i - 1][j], f5[i][j - 1]) + p5[i][j];
        }
    }
  //  cout << f2[n][m] << " " << f5[n][m] << "\n";
  
    if (pos != make_pair(-INF, INF)){
        for (int i = 1; i < pos.fi; i++) path += 'D';
        for (int j = 1; j < pos.se; j++) path += 'L';
        for (int i = pos.fi; i < n; i++) path += 'D';
        for (int j = pos.se; j < m; j++) path += 'L';
     //   cout << 1 << "\n" << path << "\n";
    }
    int ans = min(f2[n][m], f5[n][m]);
    if (ans > 1 && !path.empty()){
        cout << 1 << "\n" << path << "\n";
        return;
    }
    string path2 = trace(2);
    string path5 = trace(5);
   // debug(path2, path5);
   
    if (ans == 1 && !path.empty()){
        if (f2[n][m] == 1) path = min(path, path2);
        if (f5[n][m] == 1) path = min(path, path5);
        cout << 1 << "\n" << path << "\n";       
        return;
    }
    else {
        if (f2[n][m] < f5[n][m]){
            cout << ans << "\n" << path2 << "\n";
            return;
        }
        else if (f2[n][m] > f5[n][m]){
            cout << ans << "\n" << path5 << "\n";
            return;
        }
        else 
            cout << ans << "\n" << min(path2, path5) << "\n";
    }
    
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    if (fopen(TASK ".inp", "r")) freopen(TASK ".inp", "r", stdin);
    
    int Test = 1;
    //cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}

