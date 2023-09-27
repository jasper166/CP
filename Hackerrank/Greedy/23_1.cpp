#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define vii vector<pii>
#define pb push_back
#define fi first
#define el cout << endl
#define se second
#define in(a) cin >> a;
#define out(a) cout << a;
#define all(x) (x).begin(), (x).end()
#define rep(a) for (int i = 0; i < (a); i++)
#define vll vector<ll>
#define vi vector<int>
#define ms(a) memset(a, sizeof(a))
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, b, a) for (int i = b; i >= a; i--)
#define faster                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
const ll MOD = 1e9 + 7;
bool cmp(pair<string, int> a, pair<string, int> b)
{
    return a.first > b.first;
}

int main()
{
    faster;
    string s;
    cin >> s;
    s+="a";
    vector<int> res;
    int cnt = 0, ans = -1e9;
    string tmp = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
        {
            ++cnt;
            // i++;
        }
        else
        {

            res.push_back(cnt);
            cnt = 0;
        }
    }
    sort(res.begin(), res.end(), greater<int>());
    for(auto x : res){
        cout<<x<<endl;
    }
    int kien = 0;
    for (int i = 0; i < res.size(); i += 2)
    {
        kien += res[i];
    }
    // cout<<"KIEN\n";
    cout << kien;
}