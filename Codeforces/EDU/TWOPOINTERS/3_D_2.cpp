#include <iostream>
#include <limits.h>
#include <cstdint>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>
#include <set>
#include <cstring>
#include <deque>
#include <stack>
#include <queue>
#include <utility> 
#include <iomanip>      // std::setprecision
#include <sstream>      // std::stringstream
using namespace std;
typedef long long l1;
typedef long long unsigned lu1;
typedef long double ld;
#define FIO std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PI acos(-1.0)
#define pb push_back
// #define SORT(A) sort(A.begin(), A.end());
// #define REVERSE(A) reverse(A.begin(), A.end());
#define deb(x) cout << #x << ": " << x << "\n"
#define PrintArray(arr) for(int i=0;i<(int)arr.size();i++)cout<<arr[i]<<" ";cout<<"\n";
#define pii pair<int,int>
#define pll pair<long long int , long long int>
#define puu pair<long long unsigned , long long unsigned>
#define int long long
const int MOD = 1e9+7;
const int INF = 1e9;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int maxDiff(int a1, int a2, int a3, int a4){
    int ar[] = {a1, a2, a3, a4};
    int diff = -INF;
    for (int i = 0; i <= 3; i++)
        for (int j = 0; j <= 3; j++)
            if(i!=j) diff = max(diff, ar[i] - ar[j]);

    return diff;
}

int32_t main()
{
    #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    #endif
    FIO;
    int t;
    t = 1;
    // cin>>t; 
    for (int tc=0;tc<t;tc++) 
    { 
        // https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/D
        // similar on IB: https://www.interviewbit.com/problems/array-3-pointers/
    int n1;
    cin >> n1;
    int caps[n1];
    for (int &i : caps) cin >> i;
    sort(caps, caps + n1);

    int n2;
    cin >> n2;
    int shirts[n2];
    for (int &i : shirts) cin >> i;
    sort(shirts, shirts + n2);

    int n3;
    cin >> n3;
    int pants[n3];
    for (int &i : pants) cin >> i;
    sort(pants, pants + n3);

    int n4;
    cin >> n4;
    int shoes[n4];
    for (int &i : shoes) cin >> i;
    sort(shoes, shoes + n4);

        int i1 = 0, i2 = 0, i3 = 0, i4 = 0, maxi = INF, a = -1, b = -1, c = -1, d = -1, diff;
       while (i1 < n1 && i2 < n2 && i3 < n3 && i4 < n4){
        diff = maxDiff(caps[i1], shirts[i2], pants[i3], shoes[i4]); 
        if (diff < maxi){
            maxi = diff;
            a = i1, b = i2, c = i3, d = i4;
            // debug(c, s, p ,sh);
        }   
        if (caps[i1] <= shirts[i2] && caps[i1] <= pants[i3] && caps[i1] <= shoes[i4])
            i1++;
        else if (shirts[i2] <= caps[i1] && shirts[i2] <= pants[i3] && shirts[i2] <= shoes[i4])
            i2++;
        else if (pants[i3] <= caps[i1] && pants[i3] <= shirts[i2] && pants[i3] <= shoes[i4])
            i3++;
        else if (shoes[i4] <= caps[i1] && shoes[i4] <= shirts[i2] && shoes[i4] <= caps[i1])
            i4++;
    }
        // cout << i1 << " " << i2 << " " << i3 << " " << i4 << '\n';
   diff = -INF;
    // if (i2 >= n2 || i1 >= n1) diff = INF;
    ckmax(diff, (int) abs(shirts[i2] - caps[i1]));
    // debug(diff);
    // if (i3 >= n3 || i2 >= n2) diff = INF;
    ckmax(diff, (int) abs(pants[i3] - shirts[i2]));
    // debug(diff);
    // if (i4 >= n4 || i3 >= n3) diff = INF;
    ckmax(diff, (int) abs(shoes[i4] - pants[i3]));
    // debug(diff);

    if (diff < maxi){
        maxi = diff;
        a = i1, b = i2, c = i3, d = i4;
    }

    // debug(c, s, p ,sh);
    cout << caps[a] << " " << shirts[b] << " " << pants[c] << " " << shoes[d] << '\n';      
    // debug(a);         
    }
 
    #ifndef ONLINE_JUDGE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}