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

int n, m;

int orz(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    int cus[m];
    multiset <int> t;
    for (int i = 0; i <= n - 1; ++i){
        int x; cin >> x;
        t.insert(x);
    }
    for (int &i : cus) cin >> i;

    for (int i : cus){
       auto k = upper_bound(t.begin(), t.end(), i);
       if (k == t.end()) cout << '-1\n';
       else {
            k--;
            cout << *k << '\n';
            t.erase(k);
        }
    }
    return 0; 
}