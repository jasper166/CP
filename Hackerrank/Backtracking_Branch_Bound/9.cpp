/**    
* LANG: C++ 
* author: atom 
* created: 30.05.2022 22:38:33
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

int n;
ll s;
int a[50];
int ans = 1e9, cnt = 0;
bool flag = false;

void atm(int i, ll cur){
    if (cur == s){
        ans = min(ans, cnt);
        flag = true;
        return;
    }
    if (cur > s) return;
    if (i >= 2 && cur + 1LL * a[i - 1] <= s){
        cnt++;
        atm(i - 1, cur + 1LL * a[i - 1]);
        cnt--;
    }
    if (i >= 2) atm(i - 1, cur);

}


int orz(){
    ios_base:: sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> s;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort (a + 1, a + n + 1);
    atm(n + 1, 0);
    if (flag && s) cout << ans << '\n';
    else cout << "-1\n";
}
