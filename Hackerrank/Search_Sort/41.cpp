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


    int n, s;
    cin >> n >> s;
    vector <int> a(n);
    for (int &i : a) cin >> i;

    int cnt = 0;
    ll sum = a[0], k = 0;
    for (int i = 1; i <= n; ++i){
        while (sum > s && i > k){
            sum -= a[k++];
        }
        // while (sum < s && i > k && a[k] < 0) sum -= a[k++];
        cout << sum << ' ' << k << '\n';
        if (sum == s){
            cnt++;
        }  
        if (i <= n - 1) sum += (ll) a[i]; 

    }
    cout << cnt << '\n';
    return 0; 
}