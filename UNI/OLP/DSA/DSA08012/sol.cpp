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

vector <int> num;
int dp[10][10][2];

int f (int pos, int cnt, int small, vector <int> &track) {
    int diff = 0;
    for (int i = 0; i < 6; i++) {
        int x = track[i];
        if (x == 1)
            diff++;
        else if (x > 1 && i)
            diff = INF;
    }
    // debug(pos, diff, track);
    if (diff > 6)
        return 0;
    if (pos == num.size()) {
        return (diff <= 6);
    }
    if (dp[pos][cnt][small] != -1)
        return dp[pos][cnt][small];
    int res = 0;
    int LIM;
    if (small) 
        LIM = 5;
    else 
        LIM = num[pos];

    for (int digit = 0; digit <= min(5, LIM); digit++) {
        vector <int> ntrack = track;
        ntrack[digit]++;
        int diff = 0;
        int nsmall = small;
        if (small == 0 && digit < LIM)
            nsmall = 1;
        for (int i = 0; i < 6; i++) {
            int x = track[i];
            if (x == 1)
                diff++;
            else if (x > 1 && i)
                diff = INF;
        }
        if (diff <= 6)
            res += f(pos + 1, diff, nsmall, ntrack);
    }
    return (dp[pos][cnt][small] = res);
}   

int solve (int x) {
    num.clear();
    while (x > 0) {
        num.push_back(x % 10);
        x /= 10;
    }
    reverse(all(num));
    debug(num);
    memset(dp, -1, sizeof dp);
    vector <int> digit = {0, 0, 0, 0, 0, 0};
    int res = f(0, 0, 0, digit);
    return res;
}

void run_case(){
    int l, r;
    cin >> l >> r;
    if (l > r) swap(l, r);
    // cout << solve(r) << "\n";
    cout << solve(r) - solve(l - 1) << "\n";
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

