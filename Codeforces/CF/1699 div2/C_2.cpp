#include<bits/stdc++.h>
#ifdef HUY
#include "C:\chitnocac/mchou.h"
#else
#define debug(...) 7 
#endif
using namespace std;
#define int long long
#define endl '\n'
#define fi first
#define se second
#define pb push_back 
#define all(x) (x).begin(), (x).end()
const int maxn = 1e6 + 5, mod = 1e9 + 7, INF = 1e9;

void solve() {
    int n; 
    cin >> n;
    int ma = -INF, mi = INF;
    int pos[maxn], a[maxn];
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        pos[a[i]] = i;
    }
    mi = ma = pos[0];
    int res = 1;
    for (int i = 1; i < n; i++){
        if (pos[i] > ma || pos[i] < mi){
            ma = max(ma, pos[i]);
            mi = min(mi, pos[i]);
        }
        else{
            res *= (ma - mi - i + 1);
            res %= mod;
        }
    }
    cout << res << endl;
}
signed main() {
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    ios_base::sync_with_stdio(NULL); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        //cout << "Case #" << k++ << ": ";
        solve();
    }
}