/**    
* LANG: C++ 
* author: atom 
* created: 23.05.2022 22:54:20
**/
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#define orz main
#define F first
#define S second
#define pii pair <int, int>
#define pb push_back
#define all(x) x.begin(), x.end()

constexpr int MOD = 1e9 + 7;
constexpr int MAX = 1e6 + 2;
 
#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif
vector<string> vec_splitter(string s) {
	s += ',';
	vector<string> res;
	while(!s.empty()) {
		res.push_back(s.substr(0, s.find(',')));
		s = s.substr(s.find(',') + 1);
	}
	return res;
}
void debug_out(
vector<string> __attribute__ ((unused)) args,
__attribute__ ((unused)) int idx, 
__attribute__ ((unused)) int LINE_NUM) { cerr << endl; } 
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
	if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
	stringstream ss; ss << H;
	cerr << args[idx] << " = " << ss.str();
	debug_out(args, idx + 1, LINE_NUM, T...);
}

#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)


ll dig_count(long long res){
    ll cn=0;
    while (res)
        {
            cn++;
            res /= 10;
        }
    return cn;
}
 
ll min_ = LONG_LONG_MAX;
 
void sinh(long long cur, ll dignum, ll lc){
    if (min_ != LONG_LONG_MAX) {
        if (lc > min_) return;
        long long res = cur*(ll) pow(9, min_-lc);
        ll cn = 0;
        while (res)
        {
            cn++;
            res /= 10;
        }
        if (cn < dignum) return;
    }
    vector <ll> cs;
    long long cur1 = cur;
    while (cur1)
    {
        cs.pb(cur1 % 10);
        cur1 /= 10;
    }
    //sort(cs.begin(),cs.end());
    for (int i = 0; i < cs.size(); i++){
        if (cs[i] == 0 || cs[i] == 1) {
            continue;
        }
        long long res = cur * cs[i];
        ll cn = 0;
        while (res)
        {
            cn++;
            res /= 10;
        }
        if (cn < dignum)
        {
            if (cur * cs[i] == cur) continue;
            sinh(cur * cs[i], dignum, lc + 1);
        }
        else if (dig_count(cur * cs[i]) == dignum)
        {
            min_ = min(min_, lc);
            return;
        }
        else
        {
            return;
        }
    }
}

int main()
{
    int t=1;
    //cin >> t;
    while (t--)
    {
        ll n;
        ll x;
        cin >> n >> x;
        for (int i=0;i<n;i++) x*=1;
        sinh(x,n,1);
        if (min_==LONG_LONG_MAX) cout << -1;
        else cout << min_;
    }
    return 0;
} 