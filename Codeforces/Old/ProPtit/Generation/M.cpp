// /**    
// * LANG: C++ 
// * author: atom 
// * created: 27.05.2022 21:45:47
// **/
// #include "bits/stdc++.h"
// using namespace std;
// using ll = long long;

// #define orz main
// #define F first
// #define S second
// #define pii pair <int, int>
// #define pb push_back
// #define all(x) x.begin(), x.end()

// constexpr int MOD = 1e9 + 7;
// constexpr int MAX = 1e6 + 2;
 
// #ifdef LOCAL
// #include "myLib.h"
// #else
// #define debug(...) 42
// #endif


// int orz(){
// 	ios_base:: sync_with_stdio(false);
// 	cin.tie(nullptr);

// 	int n;
// 	cin >> n;
// 	int a[n];
// 	int sum = 0;
// 	for (int &i : a) cin >> i, sum += i;
	

// 	vector <vector <bool>> dp(n, vector <bool>(sum + 1, false));
// 	for (int i = 0; i <= n - 1; i++) dp[i][0] = true;
// 	if (a[0] <= sum) dp[0][a[0]] = true;

// 	for (int i = 1; i <= n - 1; i++){
// 		for (int j = 1; j <= sum; j++){
// 			bool nok = dp[i - 1][j];
// 			bool ok = false;
// 			if (a[i] <= j ) ok = dp[i - 1][j - a[i]];
// 			dp[i][j] = ok | nok;
// 		}
// 	} 
// 	int ans = 1e9;
// 	for (int i = 0; i <= sum / 2; i++){
// 		if (dp[n - 1][i]) ans = min(ans, abs(sum - i) - i);
// 	}
// 	cout << ans << '\n';

// }


#include <stdio.h>
#include <math.h>

float a, b, c;
int main(){

	scanf("%f%f%f", &a, &b, &c);
	float del = b * b - 4 * a * c;
	if(del == 0)
		printf("%.2f", -b / (2 * a));
	else if(del > 0) 
		printf("%.2f %.2f", (-b + sqrt(del)) / (2 * a), (- b - sqrt(del)) / (2 * a));
	else
		printf("NO");

}