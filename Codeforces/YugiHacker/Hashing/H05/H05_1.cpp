#include <cstring>
#include <cstdio>
#include <iostream>
#define REP(i, a, b) for(int i = (a); i <=(b); ++i)
#define REPD(i, a, b) for(int i = (a); i >=(b); --i)
#define long long long

const int N = 50005;
const int MOD = 1000000007;
const long MM = (long)MOD * MOD;

using namespace std;

long H[N], R[N], power[N];
char s[N];
int n;

int getHash(int i, int j)
    { return (H[j] - H[i - 1] * power[j - i + 1] + MM) % MOD; }
int getRash(int i, int j)
    { return (R[i] - R[j + 1] * power[j - i + 1] + MM) % MOD; }
bool isPalin(int i, int j)
    {   cout << i << ' ' << j << '\n';
        return getHash(i, j) == getRash(i, j); }

int main() {

    scanf("%d\n%s", &n, s + 1);
    REP(i, 1, n) H[i] = (H[i - 1] * 26 + s[i] - 'a') % MOD;
    REPD(i, n, 1) R[i] = (R[i + 1] * 26 + s[i] - 'a') % MOD;
    power[0] = 1;
    REP(i, 1, n) power[i] = power[i - 1] * 26 % MOD;
    int ans = 0;
    REP(i, 1, n) {
        // even palindrome
        int l = 0, r = min(i, n - i);
        cout << "l r: " << l << ' ' << r << '\n';
        while (l <= r) {
            int mid = l + r >> 1;
            cout << "m: " << mid << '\n';
            if (isPalin(i - mid + 1, i + mid))
                ans = max(ans, mid << 1), l = mid + 1;
            else
                r = mid - 1;
        }
        // odd palindrome
        l = 0, r = min(i - 1, n - i);
        while (l <= r) {
            int mid = l + r >> 1;
            if (isPalin(i - mid, i + mid))
                ans = max(ans, mid << 1 | 1), l = mid + 1;
            else
                r = mid - 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}
