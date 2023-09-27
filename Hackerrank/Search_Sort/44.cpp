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


    int n;
    cin >> n;
    vector <int> a(n);
    for (int &i : a) cin >> i;

    int l = 0;
    int res = 0;
    map <int, int> mp;
    mp[a[0]]++;

    for (int l = 0, r = 0; r <= n - 2;){
        if (mp[a[r + 1]] == 0){
            r++;
            mp[a[r]] = 1;
            res = max(res, r - l + 1);
        }
        else {
            mp[a[l]]--;
            l++;
        }
    }
    cout << res << '\n';
    return 0; 
}