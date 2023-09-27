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
    if ((int) a.size() < (int) b.size()) swap(a, b);
    int N = a.size();
    int M = b.size();

    // cout << a << " " << b << "\n";
    reverse(all(a));
    reverse(all(b));
    string res = "";
    int carry = 0;
    REP(i, N){
       // cout << a[i] << " " << b[i] << "\n";
        int sum  = (a[i] - '0'  + (i < M? b[i] - '0' : 0 + carry));
       // cout << sum << "\n";
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

    // cout << a << " " << b << " " << c << "\n";
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
    // cout << have(s, 0, 1, 3);
    FOR(i, 1, n - 1)
        for (int j = 1; j + i < n; j++)
            if (have(s, 0, i, j))
                return 1;
    return 0;
}

void run_case(){
    cin >> s;
    n = s.size();
//    cout << add("123", "415") << "\n"; 
    cout << (ok()? "Yes" : "No") << "\n";
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int Test = 1;
    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}
// Codename : Jasper the Otter



