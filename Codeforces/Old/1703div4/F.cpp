#include "bits/stdc++.h"
using namespace std;
using ll = long long;
constexpr int MOD = 1e9 + 7;
constexpr int MAX = 1e6 + 2;
constexpr int INF = INT_MAX;

int t, n, a[MAX], prefix[MAX];

int main(){
	cin >> t;
	while (t--){
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		ll ans = 0;
		for (int i = 1; i <= n; i++) {
			prefix[i] = prefix[i - 1] + !(a[i] >= i);
			if (a[i] != 0 && !(a[i] >= i)) ans += prefix[a[i] - 1];
		}	
		cout << ans << '\n';
	}
		 
}
