/**    
* LANG: C++ 
* author: atom 
* created: 08.07.2022 16:59:57
**/
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#define orz main
#define F first
#define S second
#define pii pair <int, int>
#define pb push_back
#define pob pop_back
#define all(x) x.begin(), x.end()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define int long long 

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 


constexpr int MOD = 1e9 + 7;
constexpr int MAX = 2e6 + 2;
constexpr int INF = INT_MAX;
 
int t, n, m, k;
int a[MAX], idle[MAX];


bool check(int mid){
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        idle[i] = 0;
    }
    for(int i = 1; i <= n; i++){
        if (mid < a[i]){
            cnt += a[i] - mid;
        } else {
            idle[i] = mid - a[i];
        }
    }
    for(int i = 1; i <= n; i++){
        cnt -= idle[i] >> 1;
    }
	return (cnt <= 0);
}
// bs

signed orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> t;
	while (t--){
		cin >> n >> m;
		FOR(i, 1, n) a[i] = 0;
		FOR(i, 1, m){
			cin >> k;
			a[k]++;
		}

		auto ok = [] (int &x){
			int cnt = 0;
			FOR(i, 1, n) idle[i] = 0;
			FOR(i, 1, n){
				if (x < a[i])
					cnt += (a[i] - x);
				else idle[i] = x - a[i];
			}
			FOR(i, 1, n) cnt -= idle[i] / 2;
			return (cnt <= 0);
		};



		int l = 1, r = 2 * m, ans = 2 * m;
		while (l <= r){
			int mid = (l + r) / 2;
			if (ok(mid)){
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		cout << ans << '\n';
	}

		 
}
/* problem link: 

*/

