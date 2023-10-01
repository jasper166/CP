/**    
* LANG: C++ 
* author: atom 
* created: 26.05.2022 00:25:49
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
#include "myLis.h"
#else
#define debug(...) 42
#endif

int t, n;

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);


		int res = (1 & 1) + (2 | 2);
		cin >> t; 
	    while (t--){
        cin >> n;
        int a[n + 1];
        vector <int> s;
		int i;
		for (i = 1; i <= n; i++) cin >> a[i]; 
        bool ans = false;
        if(!(n & 1)){
          	ans = true;
            sort(a + 1, a + n + 1);
            i = 1;
           while (i <= n/2) {
                s.pb(a[i]);
                s.pb(a[n / 2 + i]);
                ++i;
            }
            i = 1;
            for (i = 1; i <= n - 1; ++i) {
                if(s[i] == s[i - 1]){
                    ans = false;
                    break;
                }
            }
        }
        bool ans2 = false;
        if (ans) cout << "YES\n", ans2 = true;
        else cout << "NO\n";
        if(ans2){
            for (int i = 0; i <= n - 1; ++i)
            	cout << s[i] << ' ';
            cout << '\n';
        }
    }

}
