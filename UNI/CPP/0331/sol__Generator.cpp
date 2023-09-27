#include "bits/stdc++.h"

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

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#define debugArr(...) 42
#endif

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

string s;
int n;

string add(string a, string b){
    int N = a.size();
    int M = b.size();
    if (N < M) swap(a, b);

   // cout << a << " " << b << "\n";
    string res = "";
    int carry = 0;
    PER(i, N){
//        cout << a[i] << " " << b[i] << "\n";
        int sum  = (a[i] - '0'  + (i < M? b[i] - '0' : 0) + carry);
  //      cout << sum << "\n";
        int cur  =  sum % 10;
        carry = sum / 10;
        res = (char) (cur + '0') + res;
    }
    if (carry) 
        res = (char) (carry + '0') + res;
    return res;
}


bool have(string ss, int x, int y, int z){
    string a = ss.substr(x, y);
    string b = ss.substr(x + y, z);
    string c = add(a, b);
    int w = (int) c.size();
    if (w + x + y + z > (int) ss.size())
        return 0;
    if (c == ss.substr(x + y + z, w)){
        if (x + y + z + w == (int) ss.size())
            return 1;
        return have(ss, x + y, z, w);
    }
    return 0;
}



bool ok(){
    FOR(i, 1, n - 1)
        for (int j = 1; j + i < n; j++)
            if (have(s, 0, i, j)) return 1;
    return 0;
}

ll Rand(ll a, ll b){
    return (rand() % (b - a + 1) + a);
}

void run_case(){
    ll s = Rand(100000000000, 1000000000000000);
    cout << s << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    srand(time(0));
    
    int Test = Rand(2, 5);
    cout << Test << "\n";
    FOR(i, 1, Test){

        run_case();
    }
}
// Codename : Jasper the Otter



