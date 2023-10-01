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
constexpr int MAX = 1e3 + 2;
 
#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif

int n, k;
string s;
int used[MAX];

void mySet(int &a, int &b){
	a += b;
	b = 0;
	return;
}


int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--){
		cin >> n >> k;
		int a[n + 1];
		ll ans = 0;
		for (int i = 1; i <= n; ++i){
			cin >> a[i];
			int j = a[i];
			if (j / k) ans += j / k;
			used[j % k]++;
		}

		int h[3] = {n / 3, n / 3, n / 3};
		if (n % 3 == 2){
			h[0]++;
			h[1] += 2;
			h[2]--;
		}
		else if (n % 3 == 1){
			h[1] += 2;
			h[2]--;
		}
		else {
			h[1]++;
			h[2]--;
		}

		int tmp = 0;
		for (int i = 1; i <= (k - 1) / 2; i++){
			mySet(used[k - i], used[k - i + 1]);
			int mini = used[i] < used[k - i] ? used[i] : used[k - i];
			mySet(tmp, used[i]);
			ans += mini;
			used[k - i] -= mini;
		}
		mySet(used[(k + 1) / 2], used[(k + 3) / 2]);
		ans += used[(k + 1) / 2] / 2;
		cout << ans << '\n';
		mySet(tmp, used[(k + 1) / 2]);

	} 
}
