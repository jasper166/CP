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
constexpr int MAX = 1e6 + 2;

// #ifdef LOCAL
// #include "myLib.h"
// #else
// #define debug(...) 42
// #endif

string s;
int n, d;

bool ok(int x){
    int zero = 0, one = n - d;
    int j = 0;
    int k = n;
    for (int i = 1; i <= n; i++){
        if (s[i] == '0') zero++;
        else one--;
        for (; zero > x && j < i;){
            ++j;
            if (s[j] == '0') zero--;
            else one++;
        }   
        if (zero == x ) k = min(k, one);
    }
    return (k <= x);
}


int orz(){

    ios_base:: sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--){
        cin >> s;
        d = 0;
        n = s.length();
        s = ' ' + s;
        for (int i = 1; i <= n; ++i){
            if (s[i] == '1') continue;
            else d++;
        }
        int l = -1, r = d, ans = d;
        while (l + 1 < r){
            int m = l + (r - l) / 2;
            if (ok(m)){
                r = m;
            }
            else l = m;
        }
        cout << r << '\n';
    }
    
}