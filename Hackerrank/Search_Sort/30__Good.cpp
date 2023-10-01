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

bool cmp(pii a, pii b){
    if (b.S % 2 == 0) return b.F >= a.F;
    return b.F <= a.F;
}


int orz(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);


    int n;
    cin >> n;
    int a[n];
    for (int &i : a){
        cin >> i;
    }
    sort(a, a + n);
    int i = 0, j = n / 2;
    if (n & 1) j++;
    for (int k = 0; k <= n / 2 - 1; k++)
            cout << a[i++] << ' ' << a[j++] << ' ';
    if (n & 1) cout << a[i] << '\n';
    
    return 0; 
}