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

int n;
int f[12];
int a[MAX], b[MAX];

int process(){
    string x;
    FOR(i, 1, 3 * n) 
        x += (char) (a[i] + '0');
   
//    debug(x);
    queue <pair <string, int>> q;
    q.emplace(x, 0);
    while (!q.empty()){
        auto [b, cnt] = q.front();
        q.pop();
        //debug(b);
        bool ok = 0;        
        if (is_sorted(all(b)))
            return cnt;
        string half_f1 = b.substr(0, 2 * n);
        string half_s1 = b.substr(n, 3 * n - 1);
        string half_f2 = b.substr(2 * n, 3 * n - 1);
        string half_s2 = b.substr(0, n);
        
       // debug(b, half_f1);

        sort(all(half_f1));
        sort(all(half_s1));
        
        //debug(half_f1, half_f2);
        //debug(half_s2, half_s1);
        
        q.emplace(half_f1 + half_f2, cnt + 1);
        q.emplace(half_s2 + half_s1, cnt + 1);
        cnt++;
    }
    //return cnt;
}

void run_case(){
    cin >> n;
    FOR(i, 1, 3 * n)
        a[i] = i;
    int cnt = 0;
    do {
        //cout << "\n";
        int best = process();
        f[best]++;
    //    if (best == 2 && a[3] == 4 && a[4] == 5 && a[6] == 6){         
      //          FOR(i, 1, 3 * n) cout << a[i] << " \n"[i == 3 * n];
        //        cnt++;
    } while (next_permutation(a + 1, a + 1 + 3 * n));
//    debug(cnt);
    debug(f[1], f[2], f[3]);

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

