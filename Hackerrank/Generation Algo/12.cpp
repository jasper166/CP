/**    
* LANG: C++ 
* author: atom 
* created: 27.05.2022 12:46:06
**/
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#define orz main
#define F first
#define S second
#define pii pair <int, int>
#define pb push_back
#define all(x) x.begin(), x.end()

constexpr int MOD = 1e9 + 7;
constexpr int MAX = 1e6 + 2;
 
#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif

int n, k;

bool ok(string s){
    int cnt = 0, unique = 0, appear = 0;
    for (int i = 0; i <= (int) s.length() - 1; ++i){
        if (s[i] == '1'){
        	cnt = 0;
            while (s[i] == '1'){
                i++;
                cnt++;
            }
            if (cnt == k) unique++;
            if (cnt >= k) appear++;
        }
    }
    return (unique == 1 && appear == 1);
}


int orz(){
    ios_base:: sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    vector <string> ans;
    set <string> ans2;
    for (int i = 0; i <= (1 << n) - 1; i++){
        string tmp = "";
        int cnt = 0;
        for (int j = 0; j <= n - 1; j++){
            if (i & (1 << j)){
                tmp = "1" + tmp;
                cnt++;
            }
            else tmp = "0" + tmp;
        }
        if (cnt == k) ans.pb(tmp);
        if (ok(tmp)) ans2.insert(tmp);
    }

    for (string s : ans) cout << s << ' ';
    cout << '\n';
    for (string s : ans2) cout << s << ' ';
    cout << '\n';
}