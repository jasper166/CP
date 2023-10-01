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


    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    for (int &i : a) cin >> i;

    int l = 0;
    ll res = 0;
    map <int, int> mp;

    int cnt = 0;
    for (int r = 0; r <= n - 1; ++r){
        mp[a[r]]++;
        if (mp[a[r]] == 1) cnt++;
        while (cnt > k){
            mp[a[l]]--;
            if (mp[a[l]] == 0) cnt--;
            l++;
        }
        res += 1ll * (r - l + 1);
    }
    cout << res << '\n';
    return 0; 
}