#include <bits/stdc++.h>

#define nl "\n"
#define fi first
#define se second
#define vt vector
#define all(x) x.begin(), x.end()
#define evoid(val) return void (cout << val)

using namespace std;

using ll = long long;
using ii = pair<int, int>;
using pl = pair<long long, long long>;
using vi = vector<int>;

const string no  =  "NO";
const string yes = "YES";

const bool multitest = 1;
const int N = 2e5 + 7;

int a[N];
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= m; ++i) cin >> a[i];

    if (k > m) evoid(no);

    for(int i = 1; i <= m; ++i)
    {
        if(a[i] > n/k+n%k!=0)evoid(no);
    }
    evoid(yes);
    // 3 2 1 3 2
}

#define task "main"
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        (void)!freopen(task".inp", "r", stdin);
        (void)!freopen(task".out", "w", stdout);
    }
    int test = 1;
    if (multitest) cin >> test;
    while (test--) {
        solve();
        cout << "\n";
    }

}
