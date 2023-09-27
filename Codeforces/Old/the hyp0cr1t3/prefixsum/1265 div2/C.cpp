/**    
* LANG: C++ 
* author: atom 
* created: 22.06.2022 17:59:47
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

int t, n, p[MAX];
int ans[3];

int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> t;
	while (t--){
		cin >> n;
		for (int i = 1; i <= n; i++){
			cin >> p[i];
		}
		memset(ans, 0, sizeof(ans));		

		if (n >= 10){

			int curMedals = 1, i = 1, j = n / 2;

			while (p[j] == p[j + 1] && j >= i) j--;
			// last possible pick
			while (i <= n / 2 && p[i] == p[i + 1]){
				i++;
				curMedals++;
			}
			// greedy the gold medals
			ans[0] = curMedals;
			// greedy the silver medals
			// i = 2 * curMedals + 1;
			i = 2 * curMedals + 1;
			while (i <= n / 2 && p[i] == p[i + 1]) i++;

			ans[1] = i - ans[0];
			ans[2] = j - ans[1] - ans[0];
			if (!(ans[0] < ans[1] && ans[0] < ans[2])) memset(ans, 0, sizeof(ans));
		}
		for (int i : ans)
			cout << i << ' ';
		end;
	}	 
}
