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
    int a[n];
    for (int &i : a) cin >> i;
    sort(a, a + n);
    ll sum = 1;
    for (int i = 0; i <= n - 1; ++i){
    	if (sum < a[i]) break;
    	sum += a[i];
    }
    cout << sum << '\n';
    return 0; 
}