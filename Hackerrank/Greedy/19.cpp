/**    
* LANG: C++ 
* author: atom 
* created: 07.06.2022 07:02:17
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


int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);
	int n, cnt = 0;
	string s;
	 cin >> s;
    n = s.size();
    s = '$' + s;

    for (int i = 1, ans = 0; i <= n; i++) {
        ans += s[i] == ')' ? -1 : 1;
        if (ans < 0) {
            cnt++;
            ans++;
            for (int j = i + 1; j <= n; j++)
                if (s[i] == '(') {
                    s[i] = ')';
                    break;
                }
        }
    }
    cout << cnt;
    return 0;
}
