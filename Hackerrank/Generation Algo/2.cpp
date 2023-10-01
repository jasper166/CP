/**    
* LANG: C++ 
* author: atom 
* created: 26.05.2022 13:04:19
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
constexpr int MAX = 1e6 + 2;
 
#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif


int n, k;
vector <int> a(1002);

void next_combination(){
	int last = a[k - 1];
	int head, tail;
	for (int i = k - 1; i >= 0; --i){
		if (a[i] < last){
			head = i;
			break;
		}
	}
	for (int i = k - 1; i >= head; --i){
		if (a[i] == a[head] + 1){
			tail = i;
			break;
		}
	}
	swap(a[head], a[tail]);


}

void next_(){

	int i = k;
	while (i >= 1 && a[i] == n - k + i) i--;
	// cout << i << '\n';
	if (i == 0){
		for (int j = 1; j <= k; j++) cout << j << ' ';
		cout << '\n';
	}
	else {
		a[i]++;
		for (int j = 1; j <= i; j++) cout << a[j] << ' ';
		for (int j = i + 1; j <= k; j++){
			a[j] = a[j - 1] + 1;
			cout << a[j] << ' ';
		}
	}

}


int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	for (int i = 1; i <= k; ++i) cin >> a[i];
	// next_combination();
	next_();
	// for (int &i : a) cout << i << '\n';
	// cout << '\n';
}
