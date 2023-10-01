#include "bits/stdc++.h"
// @Jasper
using namespace std;
using ll = long long;
using pii = pair < int, int >;

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
#define TASK "OLP45"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

string s;
vector <ll> st;
vector <char> ep;

ll perform(){
    ll a = st.back(); st.pop_back();
    ll b = st.back(); st.pop_back();
    char op = ep.back(); ep.pop_back();
    // cout << op << "\n";
    switch (op){
        case '+':
            return a + b;
        case '-':
            return b - a;
        case '*':
            return a * b;
        case '/':
            return b / a; 
    }
    return 0;
}

int order(char c){
    switch (c){
        case '+':
            return 1;
        case '-':
            return 1;
        case '*':
            return 2;
        case '/':
            return 2;
    }
    return -1;
}

void run_case(){
    cin >> s;
    ll num;
    int n = s.size();
    st.clear();
    ep.clear();

    for (int i = 0; i < n; i++){
        if (isdigit(s[i])){
            ll num = 0;
            while (i < n && isdigit(s[i])){
                num = num * 10 + s[i] - '0';
                i++;
            }
            --i;
            st.push_back(num);
        }
        
        else if (s[i] == '(')
            ep.push_back(s[i]);
        
        else if (s[i] == ')'){
             while (ep.back() != '('){
                ll res = perform();
  //              cout << res << "\n";
                 st.push_back(res);
             }
             ep.pop_back();
        }
        
        else if (s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-'){
            // cout << ep.size();
            while (!ep.empty() && order(s[i]) <= order(ep.back())){
                ll res = perform();
                st.push_back(res);
                // ep.pop_back();
            }
            ep.push_back(s[i]);
        }
        
        else ep.push_back(s[i]);
    }
    
   while (!ep.empty())
       st.push_back(perform());
            
    cout << st.back() << "\n";
/*
   for (auto x : st) cout << x << " ";
    cout << "\n";
    for (auto x : ep) cout << x << " ";
    cout << "\n";
    */
}

signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    if (fopen(TASK ".inp", "r"))
        freopen(TASK ".inp", "r", stdin);
    
    int Test = 1;
    cin >> Test;
    FOR(i, 1, Test){

        run_case();
    }
}

