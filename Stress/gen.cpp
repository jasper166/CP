#include "bits/stdc++.h"
// @Jasper
using namespace std;
using ll = long long;
using pii = pair < int, int >;

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
#else
#define debug(...) 166
#define debugArr(...) 166
#endif


const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e2;

bool vis[MAX][MAX];

char c(int x) {
    return (x & 1)? ('.') : ('*');
}

void run_case() {
   int n = uid(1, 5);
   int m = uid(1, 5);
   
   cout << n << " " << m << "\n";
   int x1 = uid(1, n);
   int y1 = uid(1, m);
   vis[x1][y1] = 1;

   
    int y2, x2;
   do {
        x2 = uid(1, n);
        y2 = uid(1, m);
   } while (x2 == x1 && y2 == y1);
   FOR(i, 1, n) {
        FOR(j, 1, m) {
            if (i == x1 && j == y1) cout << "S";
            else if (i == x2 && j == y2) cout << "T";
            else cout << c(uid(1, n) & 1);
        }
        cout << "\n";
   }
   // shuffle(primes.begin(), primes.end(), rd);
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    cout << Test << "\n";
    for (int test = 1; test <= Test; test++){

        run_case();
    }
}

