/**    
* LANG: C++ 
* author: atom 
* created: 07.06.2022 01:21:11
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

int n, s, m;

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> s >> m;
	int ans = 0;
	if ((s - s / 7) * n < s * m) ans = -1;
	else {
		ans = 1;
		int have = n, spare = 0;
		for (int i = 1; i <= s; i++){
			if (i % 6 != 0){
				if (have < m){
					ans++;
					have += n;
				}
				else spare++;
			}
			else {
				if (have < m && spare){
					spare--;
					ans++;
					have += n;
				}
			}
			have -= m;
			if (have < 0){
				ans = -1;
				break;
			}
		}
	}
	cout << ans << '\n';
		 
}
