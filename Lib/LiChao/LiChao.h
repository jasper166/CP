#include "bits/stdc++.h"
//@etohari
using namespace std;

template < class T > bool minimum(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template < class T > bool maximum(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

#define WIFE "Dao Bich Ngoc"
#define el "\n"
#define fi first        
#define se second
#define bit(mask,i) ((mask >> i)&1)
#define cntbit(mask) __builtin_popcountll(mask)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define uniquev(v) sort(all(v)), (v).resize(unique(all(v)) - (v).begin())
#define sz(s) (int)s.size()
#define __lcm(a,b) (1ll * a / __gcd(1ll * a, 1ll * b) * b)
#define rand(l, r) uniform_int_distribution < int64_t > (l, r)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 1e6 + 10;
const int MAXM = 1e6 + 10;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

const int DX[] = { };
const int DY[] = { };

class li_chao_tree_t {
public:
        inline static vector < int64_t > query_point;

        class line_t {
        public:
                int64_t a, b;
                int64_t operator () (const int64_t& x) const { return a * x + b; }
                line_t() = default;
                line_t(const int64_t& _a, const int64_t& _b) : a(_a), b(_b) {};
        };

        li_chao_tree_t* left, * right;
        int64_t l, r, m;
        line_t line;

        li_chao_tree_t(int32_t l = 0, int32_t r = query_point.size() - 1) {
                this->l = query_point[l];
                this->r = query_point[r];
                int32_t m = (l + r) / 2;
                this->m = query_point[m];
                if (l != r) {
                        left = new li_chao_tree_t(l, m);
                        right = new li_chao_tree_t(m + 1, r);
                }
                line.a = 0;
                line.b = 0;
        }

        int64_t get_max(const int64_t& x) {
                if (l == r) {
                        return line(x);
                }
                else if (m >= x) {
                        return max(line(x), left->get_max(x));
                }
                else {
                        return max(line(x), right->get_max(x));
                }
        }

        void update(const int64_t& a, const int64_t& b) {
                line_t new_line(a, b);
                bool check_l = new_line(l) >= line(l);
                bool check_r = new_line(r) >= line(r);
                if (check_l && check_r) {
                        line = new_line;
                }
                else if (check_l || check_r) {
                        left->update(a, b);
                        right->update(a, b);
                }
        }
};

void etohari() {

}

signed main() {
        cin.tie(NULL)->sync_with_stdio(false);

        int test = 1;
        cin >> test;

        for (int i_test = 1; i_test <= test; i_test++) {
                etohari();
        }

        return (0 ^ 0);
}
/*
        Hi I'm Powder
        fb.com/hai290605
        ICPC WORLD FINALS GO GO
*/
