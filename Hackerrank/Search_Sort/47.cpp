/*    
 *     @Author: Hiu 
 *  @Handle: at0miccat
 */
#include "bits/stdc++.h"
#define orz main
#define F first
#define S second
#define pii pair<int, int>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int MAX = 1e4 + 2;


int orz(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);

    cout << fixed << setprecision(6);

    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i <= n - 1; ++i) cin >> a[i];
    double l = 0, r = 1e18, ans = 1e18;
    for (int i = 0; i < 200; ++i){
        double m = (l + r) / 2;
        ll cnt = 0;
        for (int i : a){
            cnt += 1ll * (i / m);
            if (cnt >= k) break;
        }   
        if (cnt >= k){
            l = m;
            ans = m;
        }
        else r = m;
    }
    cout << ans << '\n';
    return 0; 
}   