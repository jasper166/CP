/**    
* LANG: C++ 
* author: atom 
* created: 07.06.2022 09:56:51
**/
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#define orz main
#define F first
#define S second
#define pii pair <int, int>
#define pb push_back
#define all(x) x.begin(), x.end()

constexpr int MOD = 1e9 + 7;
constexpr int MAX = 1e6 + 2;
 
#ifdef LOCAL
#include "myLib.h"
#else
#define debug(...) 42
#endif

int n, k, m, p;
string s;

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

ll lcm (ll a, ll b){
    return a * b / (__gcd(a, b));
}

int d[202];

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

int orz(){
	ios_base:: sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--){
		cin >> n >> s;
		int a[n + 1];
		for (int i = 1; i <= n; i++) cin >> a[i];
		s = '$' + s;

		int v[n + 1];
		v[0] = 0;
		int i = 0;
		for (char &c : s){
			v[i + 1] = (c == 'B');  
			v[i + 1] += v[i];
			i++;
		}

		ll ans = 1;
		for (int i = 1; i <= n; i++){
			if (!d[i]){
				string y = "";
				int j = i;
				y += s[i];
				d[i] = 1;
				j = a[i];
				for (; !d[j] == 0; j = a[j]){
					y += s[j];
					d[j] = 1;
				}
				ll p = KMP(y);
				ll g = (ans * p) / lcm(ans, p);
				ans = ans * p;
				ans /= g;
			}
		}
		cout << ans << '\n';	
		memset(d, 0, sizeof(d));
	} 
}
