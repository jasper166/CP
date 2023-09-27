#include <bits/stdc++.h>

#define CHECK(cond) do { if (!(cond)) {\
  exit(1);\
} } while(0)

using namespace std;

struct node
{
    // The longest proper prefix of the palindrome that is also its suffix.
    node *prefsuf;
    // The longest proper prefix-suffix of the palindrome,
    // and is at least twice as short.
    node *prefsuf2;
    // The palindrome resulting from removal of the first and last characters.
    node *shorter;
    // The actual length of the prefix-suffix, since prefsuf may initialy point
    // to a longer palindrome that needs to be shortened by following "shorter"
    // links.
    int prefsuf_len;
    // Center position and length of the palindrome.
    int p, len;
    // The maximum number of operations we can save constructing this palindrome.
    int saved;
    // A temporary list of children, for DFS on the tree.
    list<node*> children;
    // A list of nodes pointing to this node with prefsuf.
    list<node*> prefsuf_targets;
    node(node *shorter_, int p_, int len_)
        : prefsuf(0), prefsuf2(0),
          shorter(shorter_), prefsuf_len(0), p(p_), len(len_), saved(-1) {}
    int end()
    {
        return p + len;
    }
    int start()
    {
        return p - len;
    }
};

struct graph
{
    // For each position in the string, pointer to the node representing
    // the longest palindrome centered at this node.
    vector<node *> L;
    // A list of pointers to all the nodes.
    vector<node *> all;
    // The radii of the largest palindrome centered at the given character.
    vector<int> radius;
    void build(const char *w, int n)
    {
        vector<node *> G;
        L.clear();
        L.resize(n+1, 0);
        radius.clear();
        radius.resize(n+1, 0);
        all.push_back(new node(0, 0, 0));
        L[0] = all[0];
        node *prev = all[0];
        for(int i = 0; i < n;)
        {
            G.clear();
            while (0 <= i - radius[i] - 1 && i + radius[i] < n &&
                    w[i + radius[i]] == w[i - radius[i] - 1])
            {
                prev = new node(prev, i, ++(radius[i]));
                all.push_back(prev);
                G.push_back(prev);
            }
            L[i] = prev;
            prev = all[0];
            int g = i, G_start = 0;
            radius[++i] = 0;
            if (G.empty()) for (; i < radius[g] + g; ++i)
                {
                    node *n = L[g];
                    CHECK(2*g-i>=0);
                    CHECK(n);
                    int R = g + radius[g] - i, r = radius[2*g-i];
                    if (R > r)
                    {
                        radius[i] = r;
                        node *m = L[2*g-i];
                        L[i] = m;
                        radius[i+1] = 0;
                    }
                    else
                    {
                        prev = L[2*g-i];
                        CHECK(prev->len == r);
                        radius[i] = R;
                        for (int j = 0; j < r-R; ++j)
                            prev = prev->shorter;
                        L[i] = prev;
                        goto next;
                    }
                }
            else for (; i < radius[g] + g; ++i)
                {
                    CHECK(G_start < G.size());
                    while(true)
                    {
                        node *n = G[G_start];
                        CHECK(2*g-i>=0);
                        CHECK(n);
                        int R = n->end() - i, r = radius[2*g-i];
                        if (R > r)
                        {
                            radius[i] = r;
                            node *m = L[2*g-i];
                            L[i] = m;
                            radius[i+1] = 0;
                            break;
                        }
                        else
                        {
                            G_start++;
                            node *m = L[2*g-i];
                            CHECK(m->len == r);
                            n->prefsuf = m;
                            n->prefsuf_len = R;
                            if (G_start == G.size())
                            {
                                radius[i] = R;
                                prev = m;
                                for (int j = 0; j < r-R; ++j)
                                    prev = prev->shorter;
                                L[i] = prev;
                                goto next;
                            }
                        }
                    }
                }
next:
            ;
        }
    }
    ~graph()
    {
        for (int i = 0; i < all.size(); ++i) delete all[i];
    }
    void adjust_prefsuf();
    void adjust_prefsuf2();
    void make_prefsuf_targets();
    void make_prefsuf_children();
    int dp();
};

void graph::make_prefsuf_targets()
{
    for (int i = 0; i < all.size(); ++i)
    {
        all[i]->children.clear();
        all[i]->prefsuf_targets.clear();
    }
    for (int i = 0; i < all.size(); ++i)
    {
        node *n = all[i];
        if (n->shorter)
            n->shorter->children.push_back(n);
        if (n->prefsuf)
            n->prefsuf->prefsuf_targets.push_back(n);
    }
}

void adjust_prefsuf_rec(node *n, vector<node *> *stack)
{
    stack->push_back(n);
    for (list<node*>::iterator it = n->prefsuf_targets.begin();
            it != n->prefsuf_targets.end(); ++it)
    {
        node *m = *it;
        CHECK(m->prefsuf_len < stack->size());
        m->prefsuf = (*stack)[m->prefsuf_len];
    }
    for (list<node*>::iterator it = n->children.begin(); it != n->children.end();
            ++it)
    {
        adjust_prefsuf_rec(*it, stack);
    }
    stack->pop_back();
}

// Adjusts prefsuf pointers so that they point to the right (short) palindrome.
void graph::adjust_prefsuf()
{
    make_prefsuf_targets();
    for (int i = 0; i < all.size(); ++i)
    {
        node *n = all[i];
        if (n->shorter) continue;
        vector<node *> stack;
        adjust_prefsuf_rec(n, &stack);
    }
}

void graph::make_prefsuf_children()
{
    for (int i = 0; i < all.size(); ++i)
    {
        all[i]->children.clear();
    }
    for (int i = 0; i < all.size(); ++i)
    {
        node *n = all[i];
        if (!(n->prefsuf)) continue;
        n->prefsuf->children.push_back(n);
    }
}

bool prefsuf2_compare(const node *a, const node *b)
{
    return a->len < b->len;
}

void adjust_prefsuf2_rec(node *n, vector<node *> *stack)
{
    if (!stack->empty())
    {
        CHECK(stack->back()->len < n->len);
    }
    node fake_node(0,0,0);
    fake_node.len = n->len/2;
    vector<node*>::iterator it = upper_bound(
                                     stack->begin(), stack->end(), &fake_node, prefsuf2_compare);
    if (it != stack->begin())
    {
        CHECK(it == stack->end() || (*it)->len > n->len/2);
        --it;
        n->prefsuf2 = *it;
        CHECK(n->prefsuf2->len <= n->len/2);
    }
    else
    {
        n->prefsuf2 = 0;
    }
    stack->push_back(n);
    for (list<node*>::iterator it = n->children.begin(); it != n->children.end();
            ++it)
    {
        adjust_prefsuf2_rec(*it, stack);
    }
    stack->pop_back();
}

// Find prefix-suffixes that fit in half-palindromes.
void graph::adjust_prefsuf2()
{
    make_prefsuf_children();
    for (int i = 0; i < all.size(); ++i)
    {
        node *n = all[i];
        if (n->prefsuf) continue;
        vector<node *> stack;
        adjust_prefsuf2_rec(n, &stack);
    }
}

int dp_rec(node *n)
{
    if (n->saved != -1) return n->saved;
    int val = n->len > 0 ? n->len - 1 : 0;
    if (n->prefsuf2)
        val = dp_rec(n->prefsuf2) + n->len - 1;
    if (n->shorter)
        val = max(val, dp_rec(n->shorter)+(n->len>1));
    return n->saved = val;
}

// Computes the actual solution.
int graph::dp()
{
    int saved = 0;
    for (int i = 0; i < all.size(); ++i)
        saved = max(saved, dp_rec(all[i]));
    return saved;
}

int alg(const char *w, int n)
{
    std::vector<node*> nodes(n);
    graph G;
    G.build(w, n);
    G.adjust_prefsuf();
    G.adjust_prefsuf2();
    int result = G.dp();
    return n - result;
}


int main()
{
    int Z;
    freopen("VIRUS.INP","r",stdin);
    freopen("VIRUS.OUT","w",stdout);
    cin >> Z;
    while(Z--)
    {
        string s;
        cin >> s;
        cout << alg(s.c_str(), s.size()) << endl;
    }
}

