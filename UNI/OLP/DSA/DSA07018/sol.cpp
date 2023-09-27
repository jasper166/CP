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
const int MAX = 1e4 + 5;

int cnt[MAX];
void run_case(){
    string a, b;
    memset(cnt, 0, sizeof cnt);
    getline(cin, a);
    getline(cin, b);
    debug(a, b);
    int A = (int) a.size();
    vector <int> v;
    for (int i = 0; i < A; i++) {
        if (isdigit(a[i])) {
            int f = 0;
            while (i < A && isdigit(a[i])) {
                f = f * 10 + (a[i] - '0');
                i++;
            }
            i += 3;
            int s = 0;
            while (i < A && isdigit(a[i])) {
                s = s * 10 + (a[i] - '0');
                i++;
            }
            cnt[s] += f;
            v.push_back(s);
        }
    }
    int B = (int) b.size();
    for (int i = B - 1; i >= 0; i--) {
        if (isdigit(b[i])) {
            string s;
            while (i >= 0 && isdigit(b[i])) {
                s = b[i] + s;
                i--;
            }
            i -= 3;
            string f;
            while (i >= 0 && isdigit(b[i])) {
                f = b[i] + f;
                i--;
            }
            int x = stoi(s);
            int y = stoi(f);
            cnt[x] += y;
            v.push_back(x);
            // debug(x, y);
        }
    }
    
    sort(all(v), greater <int>());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    debug(v);
    // for (auto x : v) 
    for (int i = 0; i < v.size() - 1; i++) {
        cout << cnt[v[i]] << "*x^" << v[i] << " + ";
    }
    cout << cnt[v.back()] << "*x^" << v.back() << "\n";
    
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    if (fopen(TASK ".inp", "r")) freopen(TASK ".inp", "r", stdin);
    
    int Test = 1;
    cin >> Test;
    cin.ignore();
    FOR(i, 1, Test){

        run_case();
    }
}

