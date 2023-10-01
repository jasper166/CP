/*    
 *     @Author: Hiu 
 *  @Handle: at0miccat
 */
#include "bits/stdc++.h"
#define orz main
#define F first
#define S second
#define pb push_back
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int MAX = 1e4 + 2;


int orz(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);


    int n, m;
    cin >> n >> m;
    vector <int> a(n), b(m);
    for (int &i : a){
        cin >> i;
    }
    for (int &i : b){
        cin >> i;
    }
    sort(all(a));
    sort(all(b));
    vector <int> c, d;
    int i = 0, j = 0;
    while (i <= n - 1 && j <= m - 1){
        if (a[i] == b[j]){
            c.pb(a[i]);
            d.pb(a[i]);
            i++;
            j++;
        }
        else if (a[i] > b[j]){
            d.pb(b[j]);
            j++;
        }
        else {
            d.pb(a[i]);
            i++;
        }
    }
    while (i <= n - 1) d.pb(a[i++]);
    while (j <= m - 1) d.pb(b[j++]);
    for (int i : c) cout << i << ' ';
    cout  << '\n';
    for (int i : d) cout << i << ' ';
    return 0; 
}