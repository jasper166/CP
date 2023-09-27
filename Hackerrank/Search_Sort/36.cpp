/*    
 *     @Author: Hiu 
 *  @Handle: at0miccat
 */
#include "bits/stdc++.h"
#define orz main
#define F first
#define S second
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int MAX = 1e4 + 2;

int n, m;
vector <int> a;

int last_pos(int i, int x){
    int l = i + 1, r = n - 1, ans = -1;
    while (l <= r){
        int mid = l + (r - l) / 2;
        if (x >= a[mid]){
            l = mid + 1;
            ans = mid;
        }
        else r = mid - 1;
    }
    return ans;
}

int orz(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    a.resize(n);
    for (int &i : a) cin >> i;
    sort(all(a));

    int cnt = 0;
    for (int i = 0; i <= n - 1; ++i){
        int k = last_pos(i, m - a[i]);
        if (k != -1){
            cnt++;
            a[k] = m;
        }
    }
    cout << n - cnt << '\n';
    return 0; 
}