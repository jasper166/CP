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

int orz(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    a.resize(n);
    for (int &i : a) cin >> i;
    sort(all(a));

    int i = 0, j = n - 1;
    int cnt = 0; 
    while (i < j){
        if (a[i] + a[j] <= m){
            cnt++;
            i++;
            j--;
        }
        else j--;
    }
    cout << n - cnt << '\n';
    return 0; 
}