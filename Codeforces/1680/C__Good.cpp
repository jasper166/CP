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
    int arr[2] = {0};
    int j = 0;
    int k = n;
    arr[1] = n - d;

    for (int i = 1; i <= n; i++){
        if (s[i] == '0') arr[0]++;
        else arr[1]--;
        for (; arr[0] > x && j < i;){
            j++;
            if (s[j] == '0') arr[0]--;
            else arr[1]++;
        }  
        if (arr[0] == x ) k = min(k, arr[1]);
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
        n = s.size();
        s = ' ' + s;
        for (int i = 1; i <= n; ++i){
            d += (s[i] == '0');
        }
        int l = -1, r = d;
        while (1 < r - l){
            int m = (r + l) / 2;
            if (ok(m)){
                r = m;
            }
            else l = m;
        }
        cout << r << '\n';
    }
    
}