#include "bits/stdc++.h"

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

#ifdef LOCAL
#include "debug.h"
#define TASK "1311D"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif

// #define int long long

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

ll f[11][11][2][2];

ll helper(string s, int x) {
    memset(f, 0, sizeof f);
    int n = s.size();

    for (int i = 0;  i <= s[0] - '0'; i++) {
        int X = 1, Y = 1;
        if (i == 0)
            Y = 0;
        if (i == s[0] - '0')
            X = 0;
        if (i == x) {
            int state = (i == x) && Y;
            f[0][state][X][Y]++;
        }
        else
            f[0][0][X][Y]++;
    }

    for (int i = 1; i < n; i++) {
        for (int k = 0; k < 10; k++) {
            for (int X = 0; X <= 1; X++) {
                for (int Y = 0; Y <= 1; Y++) {
                    for (int h = 0; h < 10; h++) {
                        if (X == 0 && h > s[i] - '0')
                            break;
                        int p = (h == x);
                        if (Y == 0 && h == 0)
                            p = 0;
                        f[i][k + p][X || h < s[i] - '0'][Y || h] += f[i - 1][k][X][Y];
                    }
                }
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i <= 9; i++) {
        ans += (i * f[n - 1][i][0][1] + i * f[n - 1][i][1][1]);
    }
    return ans;
}


void run_case(){
    int l, r; cin >> l >> r;
    string L = to_string(l - 1);
    string R = to_string(r);

    for (int i = 0; i < 10; i++) {
        cout << helper(R, i) - helper(L, i) << " ";
    }
    cout << "\n";
}
signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    
    // prepare();
    int Test = 1;
    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}



