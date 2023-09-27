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
const int BASE = 1e9 + 7;
using BigInt = vector <int>;

/*
94814663943294
94659453065882
7352110986964540053783128
*/
void Fix(BigInt &a){

    // REP(i, (int) a.size()) cout << a[i] << " ";
    while ((int) a.size() > 1 && a.back() == 0)  a.pop_back();
    int carry = 0;
    REP(i, (int) a.size()){
        a[i] += carry;
        carry = a[i] / 10;
        a[i] %= 10;
    }
    if (carry) a.push_back(carry);
}

void Print(BigInt a){
    Fix(a);
    PER(i, (int) a.size()) cout << a[i];
    cout << "\n";
}

void Scan(BigInt &a){
    string s;
    cin >> s;
    int n = (int) s.size();
    a.resize(n);
    REP(i, n) a[i] = s[n - 1 - i] - '0';
}

BigInt Integer(int x){
    string num = "";
    if (x == 0) num += '0';
    while (x){
        num = (char) (x % 10 + '0') + num;
        x /= 10;
    }
    reverse(all(num));
    BigInt ans((int) num.size());
    REP(i, (int) num.size()) ans[i] = num[i] - '0';
    return ans;
}
// Comparison
bool operator< (BigInt a, BigInt b){
    Fix(a);
    Fix(b);
    if ((int) a.size() != (int) b.size())
        return (a.size() < b.size());
    PER(i, (int) a.size()){
        if (a[i] != b[i])
            return (a[i] < b[i]);
    }
    return false;
}
bool operator> (BigInt a, BigInt b){
    return (b < a);
}

bool operator== (BigInt a, BigInt b){
    return (!(a < b) && !(a > b));
}

bool operator>= (BigInt a, BigInt b){
    return (a > b) || (a == b);
}

bool operator<= (BigInt a, BigInt b){
    return (a < b) || (a == b);
}
// Arithmetic
BigInt operator+ (BigInt a, BigInt b){
    Fix(a);
    Fix(b);
    BigInt ans;
    int carry = 0;
    REP(i, (int) max(a.size(), b.size())){
        if (i < (int) a.size()) carry += a[i];
        if (i < (int) b.size()) carry += b[i];
        ans.push_back(carry % BASE);
        carry /= BASE;
    }
    if (carry) ans.push_back(carry);
    Fix(ans);
    return ans;
}

BigInt operator- (BigInt a, BigInt b){
    Fix(a);
    Fix(b);
    BigInt ans(a.size());
    int carry = 0;
   
    REP(i, (int) a.size()){
        int cur = a[i] - (i < (int) b.size()? b[i] : 0) + carry;
        if (cur < 0)
            ans[i] = (cur + 10), carry = -1;
        else 
            ans[i] = (cur), carry = 0;
    }    
    Fix(ans);
    return ans;
}
BigInt operator* (BigInt a, BigInt b){
    Fix(a);
    Fix(b);
    BigInt ans;
    int n = (int) a.size();
    int m = (int) b.size();
    ans.assign(n + m + 1, 0);
    REP(i, n){
        REP(j, m) ans[i + j] += a[i] * b[j];
    }
    Fix(ans);
    return ans;
}

BigInt operator/ (BigInt a, BigInt b){
    Fix(a);
    Fix(b);
    BigInt ans, cur;
    if (b == Integer(0)) return Integer(-1);
    PER(i, (int) a.size()){
        cur.insert(cur.begin(), a[i]);
        int x = 0, l = 0, r = INF;
        while (l <= r){
            int m = (l + r) / 2;
            if (b * Integer(m) > cur){
                x = m;
                r = m - 1;
            }
            else l = m + 1;
        }
        cur = cur - b * Integer(x - 1);
        ans.insert(ans.begin(), (x - 1));
    }
    return ans;
}

void run_case(){
    BigInt A, B;
    Scan(A); 
    Scan(B);
    Print(A / B);
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
