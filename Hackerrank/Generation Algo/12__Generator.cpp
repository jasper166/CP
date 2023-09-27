/**    
* LANG: C++ 
* author: atom 
* created: 27.05.2022 12:46:06
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


int myRand(int l, int r){
    return rand() %  (r - l + 1) + l; 
}


int orz(){
    ios_base:: sync_with_stdio(false);
    cin.tie(nullptr);

    srand(time(NULL));
    int n = myRand(5, 8);
    int k = myRand(3, 4);
    cout << n << " " << k << '\n'; 
}