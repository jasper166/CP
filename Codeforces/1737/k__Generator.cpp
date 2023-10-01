#include <bits/stdc++.h>
// @jasper of GM go go. 
using namespace std;
using ll = long long;
using pii = pair < int, int >;
using pll = pair < ll, ll >;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) x.begin(), x.end()
 

const int MAXN = 1e6 + 5;
const int INF = 1e9 + 5;
vector <bool> mark(27, false);
ll Rand(ll l, ll r){
    return rand() % (r - l + 1) + l;
}

string RandString(int n){
    string ans = "";
    for (int i = 1; i <= n; i++){
        ans += (char) Rand(0, 25) + 'a';
    }
    return ans;
}

void run_case(){

    ll l = Rand(1, 1e5);
    ll r = Rand(l, 1e5);
    cout << l << "\n" << r << "\n";
    
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    srand(time(0));
    int Test = 1;
    // cin >> Test;
    FOR(i, 1, Test){
        run_case();
    }
}
// Codename : Jasper the Otter