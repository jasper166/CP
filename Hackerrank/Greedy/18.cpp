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

int n;

int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);
	
	cin >> n;
	int a[n];
	map <int, int> mp;
	int sum = 0;
	for (int &i : a) cin >> i, sum += i, mp[i]++;
	int ans = mp[4];
	
	ans += mp[3];
	mp[1] -= mp[3];
	if (mp[1] < 0) mp[1] = 0;

	ans += mp[2] / 2;
	mp[2] %= 2;
	if (mp[1] || mp[2]){
		if (mp[2]) ans++, mp[1] -= 2;
		if (mp[1] < 0) mp[1] = 0;
		ans += mp[1] / 4;
		mp[1] %= 4;
		if (mp[1]) ans++;
	}
	cout << ans << '\n';
}
