/**    
 *  @Author: Hiu 
 *  @Handle: at0miccat
**/
#include "bits/stdc++.h"
using namespace std;
using i64 = long long;

#define orz main
#define fi first
#define se second
#define pii pair <int, int>
#define pb push_back
#define all(x) x.begin(), x.end()

constexpr int MOD = 1e9 + 7;
constexpr int MAX = 1e5 + 2;

#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif



int orz(){

    ios_base:: sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        if (s[0] + s[1] + s[2] == s[3] + s[4] + s[5]) cout << "YES\n";
        else cout << "NO\n";
    }
    
 
}