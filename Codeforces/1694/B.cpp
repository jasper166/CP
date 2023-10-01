/**    
* LANG: C++ 
* author: atom 
* created: 16.06.2022 09:42:51
**/
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#define orz main
#define F first
#define S second
#define pii pair <int, int>
#define pb push_back
#define pob pop_back
#define all(x) x.begin(), x.end()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
constexpr int MOD = 1e9 + 7;
constexpr int MAX = 1e6 + 2;


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#define debug(x...) cout << "#L" <<__LINE__<< ": " <<" [" << #x << "] = ["; _print(x); cout << '\n';

// template and KMP stolen from VNOI
template<typename valueType, typename tagType>
class segmentTreeNode
{
public:
    int id, left, right;
    valueType val;
    tagType tag;
};

template<typename valueType,
         typename tagType,
         valueType (*merge)(valueType, valueType),
         void (*update)(segmentTreeNode<valueType, tagType>&, tagType)>
class segmentTree
{
private:
    std::vector<segmentTreeNode<valueType, tagType> > nodes;
    int leftRange, rightRange;
    valueType valueZero;
    tagType tagZero;
    
    void pushup(int cur)
    {
        nodes[cur].val = merge(nodes[cur << 1].val, nodes[cur << 1 | 1].val);
    }
    
    void pushdown(int cur)
    {
        update(nodes[cur << 1], nodes[cur].tag);
        update(nodes[cur << 1 | 1], nodes[cur].tag);
        nodes[cur].tag = tagZero;
    }
    
    void build(int cur, int l, int r, const std::vector<valueType>& initValue)
    {
        nodes[cur].id = cur;
        nodes[cur].left = l;
        nodes[cur].right = r;
        nodes[cur].tag = tagZero;
        if (l == r - 1) nodes[cur].val = initValue[l - leftRange];
        else
        {
            build(cur << 1, l, (l + r) >> 1, initValue);
            build(cur << 1 | 1, (l + r) >> 1, r, initValue);
            pushup(cur);
        }
    }
    
    void init(const std::vector<valueType>& _initValue,
              const valueType& _valueZero,
              const tagType& _tagZero)
    {
        valueZero = _valueZero;
        tagZero = _tagZero;
        nodes.resize((rightRange - leftRange) << 2);
        build(1, leftRange, rightRange, _initValue);
    }
    
    void modify(int cur, int l, int r, int L, int R, const tagType& tag)
    {
        if (l >= R || r <= L) return;
        if (L <= l && r <= R) update(nodes[cur], tag);
        else
        {
            pushdown(cur);
            modify(cur << 1, l, (l + r) >> 1, L, R, tag);
            modify(cur << 1 | 1, (l + r) >> 1, r, L, R, tag);
            pushup(cur);
        }
    }
    
    valueType query(int cur, int l, int r, int L, int R)
    {
        if (l >= R || r <= L) return valueZero;
        if (L <= l && r <= R) return nodes[cur].val;
        pushdown(cur);
        return merge(query(cur << 1, l, (l + r) >> 1, L, R),
                     query(cur << 1 | 1, (l + r) >> 1, r, L, R));
    }
    
public:
    segmentTree() {}
    
    segmentTree(int _leftRange,
                int _rightRange,
                const std::vector<valueType>& _initValue,
                const valueType& _valueZero,
                const tagType& _tagZero)
    {
        leftRange = _leftRange;
        rightRange = _rightRange;
        init(_initValue, _valueZero, _tagZero);
    }
    
    segmentTree(int size,
                const std::vector<valueType>& _initValue,
                const valueType& _valueZero,
                const tagType& _tagZero)
    {
        leftRange = 1;
        rightRange = size + 1;
        init(_initValue, _valueZero, _tagZero);
    }
    
    void modify(int l, int r, const tagType& tag)
    {
        modify(1, leftRange, rightRange, l, r, tag);
    }
    
    void modify(int p, const tagType& tag)
    {
        modify(p, p + 1, tag);
    }
    
    valueType query(int l, int r)
    {
        return query(1, leftRange, rightRange, l, r);
    }
    
    valueType query(int p)
    {
        return query(p, p + 1);
    }
};

ll KMP(string y){
	int l = y.size();
	y = '$' + y;
	int j = 0;
	vector <int> p(l + 1, 0);
	int i = 2;
	while (i <= l){
		for (; j && y[j + 1] != y[i]; j = p[j]); 
		if (y[++j] != y[i]) --j; 
		p[i++] = j;
	}
    ll ans = l;
	if (l % (l - p[l])) ans *= 1;
	else ans -= p[ans];
    return ans;
}

int t;
int n;
string s;
int orz(){
	cin.tie(nullptr) -> sync_with_stdio(false);

    cin >> t;
    while (t--){
        cin >> n >> s;
        int k = 1;
        ll ans = n;
        FOR(i, 1, n - 1){
            if (s[i - 1] != s[i]) ans += i;
        }
        cout << ans << '\n';
    }
		 
}
