#include "bits/stdc++.h"

using namespace std;
#define el "\n"
#define LL long long
#define fi first
#define se second

void solve(){
    int n, k;
    cin >> n >> k;
    int a[n + 1];
    for(int i = 1; i <= n; i++) cin >> a[i];
    LL res = 0;
    if(n <= k){
        for (int i = 1; i <= n; i++) res += a[i];
        cout << res + 1LL * n * (k - 1) - n * (n - 1) / 2<< el;
        
    }else{
        LL s = 0;
        for(int i = 1; i <= n; i++){
            s += a[i];
            if(i - k > 0){
                s -= a[i - k];
            }
            res = max(res, s);

        }
        cout << res + 1LL * k * (k - 1) / 2 << el;
    }

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin >> test;

    while(test--){
        solve();
    }
    return 0;
}