#include "bits/stdc++.h"
using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;
constexpr int MAX = 65;
constexpr int INF = INT_MAX;
int t, n, m;
int a[MAX];
int main(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> t;
	while (t--){
		cin >> n >> m;
		for (int i = 0; i < n; i++){
			cin >> a[i];
			a[i]--;
		}
		string b(m, 'B');
		for (int i = 0; i < n; i++){
			string tmp1 = b, tmp2 = b;
			tmp1[a[i]] = 'A';
			tmp2[m - a[i] - 1] = 'A';
			b = min(tmp1, tmp2);
		}
		cout << b << "\n";
	}
}


