#include "bits/stdc++.h"

using namespace std;

#define el "\n"
#define LL long long
#define fi first
#define se second
#define name "ETOHARI"
#define hacker "ETOHARI"
#define bit(a,b) ((a >> b)&1)
const int MAXN = 1e5 + 10;
const int MOD  = 1e9 + 7;
const int INF = 999999999;

int n, m;
pair < int, pair < int, int > > a[MAXN];
int main() {
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i].se.fi >> a[i].fi;
        a[i].se.se = i;
    }
    sort(a + 1, a + n + 1);
    for(int i = 2; i <= n; i++)
        if(a[i].se.fi > a[1].fi){
            cout << "YES" << el << a[i].se.se << " " << a[1].se.se;
            return 0;
        }
    cout << "NO";
    return 0;
}
/* Code không copy /
/ fb: Hà Lộc Hải /
/ và đó và đó là anh Hà Lộc Hảiiiiiiii */