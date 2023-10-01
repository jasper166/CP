#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int n, t;

int main(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> t;
	while (t--){
		cin >> n;
		int a[n];
		int sum = 0;
		bool check = false;
		for (int &i : a) cin >> i, sum += i;
		for (int i = 0; i <= n - 1; i++){
			int m = (sum - a[i]) / (n - 1);
			if (m * (n - 1) + a[i] == sum && m == a[i]) check = true; 
		}
		if (!check) cout << "NO\n";
		else cout << "YES\n";
	}
		 
}
