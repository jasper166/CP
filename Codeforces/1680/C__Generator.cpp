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

string s;
int n, d;

int orz(){

    ios_base:: sync_with_stdio(false);
    cin.tie(nullptr);

    srand(time(0));
    int t = rand() % 10 + 1;
    cout << t << '\n';
    while (t--){
        int n = rand() % 10 + 1;
        int a[n];
        string s = "";
        for (int i = 0; i <= n - 1; ++i){
            a[i] = rand() % 2 + 1;
            s += (char) (a[i] + '0');
        }
        cout << s << '\n';
    }
    
}