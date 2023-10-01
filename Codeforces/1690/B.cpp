/**    
* LANG: C++ 
* author: atom 
* created: 07.06.2022 09:56:51
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

int n;

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--){
		cin >> n;
		int a[n];
		int b[n];
		for (int &i : a) cin >> i;
		for (int &i : b) cin >> i;
		int cnt = -1, res = 0;
		string ans;
		bool flag = true;
		for (int i = 0; i < n; ++i){
			if (b[i] > a[i]){
				ans = "NO";
				flag = false;
				break;
			}
			if (a[i] && b[i]){
				if (cnt == -1){
					cnt = - (b[i] - a[i]);
				}
				else if (cnt != a[i] - b[i]){
					ans = "NO";
					flag = false;
					break;
				}
			}
			else res = max(res, a[i] - b[i]);
		}
		if (flag){
			ans = (cnt == -1 || res <= cnt)? "YES" : "NO";
		}
		cout << ans << '\n';
	} 
}
