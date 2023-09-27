#include "bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

using namespace std;


constexpr int MOD = (int) 1e9 + 7;
constexpr int INF = (int) 1e9;
constexpr int MAX = (int) 1e6 + 2;

int x;
int a[4], cnt[4];

int orz() {
	cin.tie(nullptr) -> sync_with_stdio(false);


	int t;
	cin >> t;
	while (t--) {

		cin >> x;
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= 3; i++) cin >> a[i];
		while (x) {
			cnt[x]++;
			x = a[x];
		}
		if (cnt[1] && cnt[2] && cnt[3]) cout << "YES\n";
		else cout << "NO\n";
	}


}
/* problem link:

*/

