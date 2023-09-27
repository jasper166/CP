/*    
 *     @Author: Hiu 
 *  @Handle: at0miccat
 */
#include "bits/stdc++.h"
#define orz main
#define F first
#define S second
#define pb push_back
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int MAX = 1e5 + 2;

map <string, int> freq;

bool cmp1(string a, string b){
    if (a.length() == b.length()) return a < b;
    else return a.length() < b.length();
}

bool cmp2(string a, string b){
    if (freq[a] == freq[b]) return a < b;
    else return freq[a] > freq[b];
}


int orz(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector <string> v;

    while (n--){
        string s;
        cin >> s;
        v.pb(s);
        freq[s]++;
    }
    sort(all(v));
    for (string i : v) cout << i << ' ';
    cout << '\n';
    
    sort(all(v), greater <string> ());
    for (string i : v) cout << i << ' ';
    cout << '\n';

    sort(all(v), cmp1);
    for (string i : v) cout << i << ' ';
    cout << '\n';

    sort(all(v), cmp2);
    for (string i : v) cout << i << ' ';
    cout << '\n';

    return 0; 
}