/**    
* LANG: C++ 
* author: atom 
* STRESS_TEST
**/
#include "bits/stdc++.h"
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long Rand(long long l, long long h) {
	return uniform_int_distribution<long long>(l, h)(rng);
}

string Rand_string(long long n){
	string s = "";
	for (int i = 0; i <= n - 1; i++){
		s += (char) (Rand(0, 25) + 'a');
	}
	return s;
}

int main(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	int n = (int) Rand(10, 20);
	int s = (int) Rand(100, 500);
	cout << n << " " << s << '\n';
	int a[n + 1];
	for (int i = 1; i <= n; ++i) a[i] = (int) Rand(25, 50);
	for (int i = 1; i <= n; ++i) cout << a[i] << ' ';
	cout << '\n';

	return 0;
}