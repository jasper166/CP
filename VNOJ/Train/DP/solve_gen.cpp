/**    
* LANG: C++ 
* author: atom 
* STRESS_TEST
**/
#include "bits/stdc++.h"
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long Rand(long long l, long long h) {
    return uniform_int_distribution<long long>(l, h)(rng);
}

string Rand_string(long long n){
    string s = "";
    for (int i = 0; i <= n - 1; i++){
        s += (char) (Rand(0, 25) + 'a');
    }
    return s;
}

int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(nullptr);

    int n = Rand(3, 6);
    int r = Rand(1, 10);
    cout << n << " " << r << "\n";
    int a[n + 1][n + 1];
    for (int i = 1; i <= n; i++)  for (int j = 1; j <= n; j++){
        a[i][j] = Rand(0, 10);
        cout << a[i][j] << " \n"[j ==n];
    }
     for (int i = 1; i <= r; i++){
        int seed = Rand(1, n);
        int cnt[102];
        memset(cnt, 0, sizeof(cnt));
        for (int j = 1; j <= seed; j++){
            int x = Rand(1, n);
            while (cnt[x] == 1){
                x = Rand(1, n);
            }
            cnt[x]++;
            cout << x << " \n"[j == seed];
        }
     }
    return 0;
}