#include "bits/stdc++.h"
#define orz main
#define F first
#define S second
#define pii pair<int, int>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int MAX = 1e6 + 2;

double esp = 0.000001;
double sum_bf = 0;
int n, k;
int a[MAX];


int orz(){
    ios_base:: sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(6);

    cin >> n >> k;
    for (int i = 0; i <= n - 1; ++i){
    	cin >> a[i];
    	sum_bf += (double) a[i];
    }
    double l = 0, r = 1e18;
    double ans = 0;

    for (int i = 0; i < 200; ++i){
    	double m = (r + l) / 2;
        double cost = 0;
        for (int i = 0; i <= n - 1; ++i){
            if (a[i] >= m)
                cost += (double) (abs(a[i] - m) * k / 100);
        }
        double res = sum_bf - cost - (double) n * m;

    	if (res <= esp && res >= 0) ans = m;
        else if (res > esp) l = m;
    	else r = m;
    }
    cout << ans << '\n';
    return 0; 
}   