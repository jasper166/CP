/**    
 *  @Author: Hiu 
 *  @Handle: at0miccat
**/
#include "bits/stdc++.h"
using namespace std;
using i64 = long long;

#define orz main
#define fi first
#define se second
#define pii pair <int, int>
#define pb push_back
#define all(x) x.begin(), x.end()

constexpr int MOD = 1e9 + 7;
constexpr int MAX = 1e6 + 2;

// #ifdef LOCAL
// #include "myLib.h"
// #else
// #define debug(...) 42
// #endif

int orz(){

    ios_base:: sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--){
    	i64 n;
    	cin >> n;
    	if (n < 4 || n % 2 != 0) cout << "-1\n";
    	else {
    		i64 a, b;
    		a = n / 4;
    		b = n / 6;
    		if (n % 6 != 0) b++;
    		cout << b <<  ' ' << a << '\n';
    	}
    }
    
}