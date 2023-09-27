/**    
* LANG: C++ 
* author: atom 
* created: 30.05.2022 18:27:14
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
vector <char> ans;
bool a[20][20];
bool flag = false;

void bt(int i, int j){
    if (i == n && j == n){
        for (char v : ans) cout << v;
        cout << '\n';
        flag = true;
        return;
    }
    else {
        if (a[i + 1][j]){
            ans.pb('D');
            bt(i + 1, j);
            ans.pop_back();
        }
        if (a[i][j + 1]){
            ans.pb('R');
            bt(i, j + 1);
            ans.pop_back();
        }
    }
}


int orz(){
    ios_base:: sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; ++j) cin >> a[i][j];
    bt(1, 1);
    if (!flag) cout << "-1\n";
}
