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
    vector <int> a(n);
    for (int &i : a){
        cin >> i;
    }
    for (int i = 1; i <= n - 1; i++){
        if ((i + 1) & 1){
            if (a[i] > a[i - 1]) swap(a[i], a[i - 1]);
        }
        else {
            if (a[i] < a[i - 1]) swap(a[i], a[i - 1]);
        }
    }
    for (int i : a) cout << i << ' ';
    return 0; 
}