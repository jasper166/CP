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

    map <ll, int> mp;
	mp[0] = 1;
    ll prefix = 0, cnt = 0;
	for (int i = 0; i <= n - 1; ++i){
		prefix += (a[i] + n) % n;
		prefix = (prefix + n) % n;
		cnt += (mp[prefix]);
		mp[prefix]++;
	}
    cout << cnt << '\n';
    return 0; 
}