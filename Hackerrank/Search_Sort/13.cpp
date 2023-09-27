/*    
 *     @Author: Hiu 
 *  @Handle: at0miccat
 */
#include "bits/stdc++.h"
#define orz main
#define F first
#define S second
#define pb push_back
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int MAX = 1e4 + 2;


int orz(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int a[n];
    for (int &i : a) cin >>i;
    sort(a, a + n, greater <int> ());
    int f = 0;
    ll sum = 0;
    for (int i = 0; i <= n - 1; i++){
        sum += 1ll * (a[i] - f++);
    }
    cout << sum << '\n';
    return 0; 
}