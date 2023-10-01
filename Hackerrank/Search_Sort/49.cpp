#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;
int a[100001] = {0};
int main() {
    int n;
    ll k;cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    double r = 1e13, l = 0;
    double luu = 0;
    for(int i = 0; i < 250; i++) {
        double m = (r+l)/2;
        if(l >= r) break;
        ll cnt = 0;
        for(int j = 0; j < n; j++) {
            ll res = (ll)a[j]/m;
            cnt += res;
            if(cnt > k) break;
        }
        if(cnt == k) {
            l = m;
            if(luu < m) {
                luu = m;
            }
        } else if(cnt < k){
            r = m;
        } else {
            l = m;
        }
    }
    cout << fixed << setprecision(6) << luu;
}