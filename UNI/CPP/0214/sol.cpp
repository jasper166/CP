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
const int MAX = 1e7 + 5;

int n, k, ans[MAX], a[MAX];

void run_case(){
    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];
    deque <int> q;
    FOR(i, 1, n){
        while (!q.empty() && a[q.back()] <= a[i])
            q.pop_back();
        q.push_back(i);
        if (q.front() + k <= i) q.pop_front();
        if (i >= k) ans[i] = a[q.front()];
    }
    FOR(i, k, n) cout << ans[i] << " \n"[i == n];
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



