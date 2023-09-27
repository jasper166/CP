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

int n;
int cnt[12];

void run_case(){
    string s;
    getline(cin, s);
    if (s == "") return;
    n = (int) s.size();
    s = '$' + s;
    FOR(i, 0, 9) cnt[i] = 0;
    FOR(i, 1, n){
        cnt[s[i] - '0']++;
    }
    bool haveEven = 0;
    vector <int> Even, Odd;
    FOR(i, 0, 9){
        if (cnt[i] % 2 == 0 && cnt[i]){
            haveEven = 1;
            Even.push_back(i);
        }
        else if (cnt[i]) Odd.push_back(i);
    
    }
    sort(all(Even), [&](const int x, const int y){
                return x < y;
            });

    sort(all(Odd), [&](const int x, const int y){
            if (cnt[x] == cnt[y]) return x < y;
            else return (cnt[x] < cnt[y]);
            });
   // cout << Even.size() << "\n";
    // cout << Odd.size() << "\n";
    //9976643055503466799
    string res = "";
    if (haveEven){
        // cout << "Even\n";
        // cout << Even.back() << "\n";
        if (Even.back() == 0 && (((int) Even.size() >= 2) || (int) Odd.size())) 
            Even.pop_back();
        
        while (!Even.empty()){
            int x = Even.back();
            cnt[x] /= 2;
            while (cnt[x]){
                res += (char) (x + '0');
                cnt[x]--;
            }
            Even.pop_back();
        }
        string ser = "";
        for (auto c : res) ser = c + ser;
        if (Odd.empty()){
            res = res + ser;
            cout << res << "\n";
            return;
        }
        int x = Odd.back();
        while (cnt[x]){
            res += (char) (x + '0');
            cnt[x]--;
        }
        res = res + ser;
    }
    else {
        // cout << "Odd\n";
        if (Odd.back() == 0 && (int) Odd.size() >= 2) Odd.pop_back();
        int x = Odd.back();
        while (cnt[x]){
            res += (char) (x + '0');
            cnt[x]--;
       }
    }
        cout << res << "\n";
    }

signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    
    int Test = 1;
    cin >> Test;
    cin.ignore();
    FOR(i, 1, Test){

        run_case();
    }
}
// Codename : Jasper the Otter




