/**    
* LANG: C++ 
* author: atom 
* created: 13.06.2022 18:19:52
**/
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#define orz main
#define F first
#define S second
#define pii pair <int, int>
#define pb push_back
#define pob pop_back
#define all(x) x.begin(), x.end()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define end cout << '\n';
constexpr int MOD = 1e9 + 7;
constexpr int MAX = 1e6 + 2;
 
#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif

struct child{
	int t, z, y;
};


int m, n;

int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> m >> n;
	child a[n];
	FOR(i, 0, n - 1) cin >> a[i].t >> a[i].z >> a[i].y;

	// sort(a, a + n, [&] (const child a, const child b){
	// 	return ((a.t + a.y / a.z) < (b.t + b.y / b.z));
	// });

	vector <int> ans(n);
	int l = 0, r = 1e9, T = n;
	while (l <= r){
		int mid = (l + r) >> 1;	
		bool ok = false;

		int balloons = 0;
		FOR(i, 0, n - 1){
			int time = a[i].t * a[i].z + a[i].y;
			int cur_bal = mid / time;
			int rem_bal = mid % time;
			balloons += cur_bal * a[i].z + min(a[i].z, rem_bal / a[i].t);
			if (balloons >= m) break;
		}

		if (balloons >= m){
			T = mid;
			int balloons = 0;
			FOR(i, 0, n - 1){
				int time = a[i].t * a[i].z + a[i].y;
				int cur_bal = T / time;
				int rem_bal = T % time;
				ans[i] = cur_bal * a[i].z + min(a[i].z, rem_bal / a[i].t);

				if (balloons + ans[i] <= m)
					balloons += ans[i];
				else if (balloons == m) ans[i] = 0;
				else {
					ans[i] = m - balloons;
					balloons = m;
				}
			}
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << T << '\n';
	FOR(i, 0, n - 1)
		cout << ans[i] << ' ';
	end;
}
