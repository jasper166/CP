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
#include "myLib.h"
#else
#define debug(...) 42
#endif

int t, n;

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> t;
	while (t--){
		cin >> n;
		int a[n];
		for (int i = 0; i <= n - 1; ++i) cin >> a[i];
		int ans = 0;
		int i = ans;
        while (i <= n - 2){
            if (a[i + 1] < a[i]){
                ans++;
                i++;
            }
            ++i;
        }
        cout << ans << '\n';
	}
		 
}
