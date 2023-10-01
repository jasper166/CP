#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int ok;
void faster()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
string s;
void ktao(int len)
{
    s = string(len, '0');
}
void next(int len)
{
    int i = len - 1;
    while(i >= 0 && s[i] == '1')    s[i--] = '0';
    if(i == -1) ok = 0;
    else
    {
        s[i] = '1';
    }
}

int main()
{
    faster();
    int n, len;
    vector<string> v;
    cin >> n;
    for(int i = 1; i <= n/2; i++)
    {
        ok = 1;
        ktao(i);
        while(ok)
        {
            string tmp = s;
            reverse(tmp.begin(), tmp.end());
            v.push_back(s + tmp);
            next(i);
        }
    }
    sort(v.begin(), v.end());
    for(auto it : v)
    {
        cout << it << '\n';
    }
}