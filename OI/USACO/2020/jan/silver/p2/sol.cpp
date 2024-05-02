#include "bits/stdc++.h"
// @JASPER'S BOILERPLATE
using namespace std;
using ll = long long;

#ifdef JASPER
#include "debug.h"
#else
#define debug(...) 166
#endif

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    #ifdef JASPER
        freopen("in1", "r", stdin);
    #endif

    // freopen("berries.in", "r", stdin);
    // freopen("berries.out", "w", stdout);
    

    // 1 : consider first K bags, take x maximum buckets from B(i) and each bucket is equal, (B(i) / x)
    // 2 : let x be the minimum candies in a bucket and all buckets have same amount, = x;

    int n, k;
    cin >> n >> k;
    vector <int> bags(n);
    for (int &x : bags) cin >> x;

   	int mX = *max_element(bags.begin(), bags.end());
    int ans = 0;
	for (int x = 1; x <= mX; ++x) {
		int cnt = 0;
		for (int i = 0; i < n; ++i) cnt += (bags[i] / x);
		if (cnt < k / 2) continue;
		if (cnt >= k) {
			ans = max(ans, (k / 2) * x); 
			continue; 
		}


		vector <int> after_bags = bags; // remaining candies;
		for (int &i : after_bags) i %= x;
		sort(after_bags.begin(), after_bags.end(), greater <int> ());

		int cur_candies = (cnt - k / 2) * x;
		int remain_boxes = (cnt - k / 2);

		debug(x, ans);
		for (int i = 0; i < n && cnt + i < k; ++i) {
			cur_candies += after_bags[i];
			--remain_boxes;
		}

		ans = max(ans, cur_candies);
		debug(x, ans);
	}

	cout << ans << "\n";
    
    return 0;
}	
// 