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

int n, k;
vector <int> a;


int orz(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    a.resize(n);
    for (int &i : a) cin >> i;

    ll l = *max_element(a.begin(), a.end());
    ll r = 1e18;
    ll res = 1e18;

    while (l <= r){
        ll m = l + (r - l) / 2;
        ll sum = 0;
        int cnt = 1;

        for (int i = 0; i <= n - 1; ++i){
            if (sum + a[i] > m){
                cnt++;
                sum = 0;
            }
            sum += 1ll * a[i];
        }


        if (cnt <= k){
            res = m;
            r = m - 1;
        }
        else l = m + 1;
    }
    cout << res << '\n';
    return 0; 
}