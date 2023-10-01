#include"bits/stdc++.h"

using namespace std;

#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define sz size()
#define ll long long
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORD(i, a, b) for(int i = a; i >= b; --i)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL);cout.tie(NULL);
#define vi vector<int>
#define vll vector<ll>
#define endl '\n'

const int MAX = 70005;
const int MOD = 10007;

int n, a[105];
int dp[MAX][2];

int Rand(int l, int r){
    return (rand() % (r + l - 1) + l);
}

int main() {
    srand(time(0));
    int t = Rand(2, 5);
    cout << t << "\n";
    while (t--){
        int n = Rand(2, 10);
        cout << n << "\n";
       FOR(i, 0, n - 1) a[i] = Rand(10, 50);
       FOR(i, 0, n - 1) cout << a[i] << " ";
        cout << "\n";
    }
}