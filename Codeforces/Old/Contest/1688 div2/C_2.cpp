#include "bits/stdc++.h"

using namespace std;
#define el "\n"
#define LL long long
#define fi first
#define se second

void solve(){
    int n, res = 0;
    cin >> n;

    

    
    for(int i = 1; i <= 2 * n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < (int)s.size(); j++)
            res ^= s[j];
    }
    string s;
    cin >> s;
    for(int j = 0; j < (int)s.size(); j++)
            res ^= s[j];
    cout << char(res) << el;
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