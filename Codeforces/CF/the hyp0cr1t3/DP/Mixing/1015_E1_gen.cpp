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

	int n = Rand(2, 100);
	int m = Rand(2, 100);
	cout << n << " " << m << "\n";
	char a[n + 1][m + 1];
	char tab[] = {'*', '.'};
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++){
		a[i][j] = tab[Rand(1, 1000) % 2];
		cout << a[i][j] << " \n"[j == m];
	}
	
	return 0;
}