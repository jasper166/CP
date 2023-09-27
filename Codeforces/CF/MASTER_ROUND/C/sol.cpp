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

void run_case(){
    cin >> n;
    map <int, vector <int>> line;
    REP(i, 1, n){
        int x; 
        cin >> x;
        line[x].push_back(i);
    }
    vector <int> res1(n), res2(n);
    vector <int> zero, one;
    FORD(i, n, 1){
        if (line[i].empty()){
            if (zero.empty() || one.empty()){
                cout << "NO\n";
                return;
            }
        }
        else if (line[i].size() == 1)
            res1[line[i][0]] = res2[line[i][1]] = i;
        else {
            res1[line[i][0]] = res2[line[i][1]] = i;
            zero.push_back(line[i][0]);
            one.push_back(line[i][1]);
        }
    }
    cout << "YES\n";
    for (auto x : res1) cout << x << " ";
    cout << "\n";
    for (auto x : res2) cout << x << " ";
    cout << "\n";

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

