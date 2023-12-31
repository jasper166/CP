#include "bits/stdc++.h"

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
const int MAX = 1e2 + 5;

int n, m;
int a[MAX][MAX];


void run_case(){
	cin >> n >> m;

    FOR(i, 1, n) FOR(j, 1, m) cin >> a[i][j];
    vector <int> ans;

    int L = 1, R = m, D = 1, U = n;

    while (L <= R && D <= U){
        FOR(i, L, R) ans.push_back(a[D][i]);
        D++;

        FOR(i, D, U) ans.push_back(a[i][R]);
        R--;

        if (D > U || L > R) break;

        FORD(i, R, L) ans.push_back(a[U][i]);
        U--;

        FORD(i, U, D) ans.push_back(a[i][L]);
        L++;
    }
    for (int i : ans) cout << i << " ";
    cout << "\n";
}


signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}
// Codename : Jasper the Otter
