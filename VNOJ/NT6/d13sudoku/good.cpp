/**
 *Author: Le Son - TK2._CHT
 *Spawn: 01/10/2006 - Ha Tinh City - VN
 *School: Ha Tinh High School for the Gifted
**/
#include <bits/stdc++.h>
#define task "testa"
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
#pragma GCC optimize("Ofast")

// struct-----pair
#define mp make_pair
#define fi first
#define se second
#define all(a_) a_.begin(), a_.end()

// vector
#define pb push_back
#define eb emplace_back
#define sz(a) (int)(a.size())

// max - min
template <class shark>
inline bool minimize(shark &a, const shark &b) { return (a > b ? (a = b), 1 : 0); }
template <class shark>
inline bool maximize(shark &a, const shark &b) { return (a < b ? (a = b), 1 : 0); }

// declare

vector<int> bitset_table(256);

ostream &operator<<(ostream &out, const vector<vector<int>> &M)
{
  for (const vector<int> &V : M)
  {
    for (int e : V)
    {
      out << e << " ";
    }
    out << '\n';
  }
  return out;
}

bool isLower(const int *ptr1, const int *ptr2)
{
  int size1, size2;

  size1 = bitset_table[*ptr1 & 0xff] + bitset_table[*ptr1 >> 8 & 0xff] +
          bitset_table[*ptr1 >> 16 & 0xff] + bitset_table[*ptr1 >> 24 & 0xff];
  size2 = bitset_table[*ptr2 & 0xff] + bitset_table[*ptr2 >> 8 & 0xff] +
          bitset_table[*ptr2 >> 16 & 0xff] + bitset_table[*ptr2 >> 24 & 0xff];
  return size1 < size2;
}

class Heap
{
private:
  int heap_size;
  vector<int *> A;
  unordered_map<int *, int> mapping;

  int parent(int i) { return (i - 1) / 2; }
  int left(int i) { return 2 * i + 1; }
  int right(int i) { return 2 * i + 2; }

  void minHeapify(int i)
  {
    int l, r, smallest;

    l = left(i);
    r = right(i);
    smallest = i;
    if (l < heap_size && isLower(A[l], A[i]))
    {
      smallest = l;
    }
    if (r < heap_size && isLower(A[r], A[smallest]))
    {
      smallest = r;
    }

    if (smallest != i)
    {
      swap(mapping[A[i]], mapping[A[smallest]]);
      swap(A[i], A[smallest]);
      minHeapify(smallest);
    }
  }

  void heapUpdateKey(int i)
  {
    if (i == 0 || !isLower(A[i], A[parent(i)]))
    {
      minHeapify(i);
    }
    else
    {
      int p = parent(i);
      while (i > 0 && isLower(A[i], A[p]))
      {
        swap(mapping[A[i]], mapping[A[p]]);
        swap(A[i], A[p]);
        i = p;
        p = parent(i);
      }
    }
  }

public:
  Heap() : heap_size(0) {}

  bool heapUpdateKey(int *ptr, int opt, int val)
  {
    if (mapping.find(ptr) == mapping.cend() || (opt == 0 && !(*ptr & (1 << val))))
    {
      return false;
    }

    if (opt == 0)
      *ptr &= ~(1 << val);
    else
      *ptr |= 1 << val;
    heapUpdateKey(mapping[ptr]);
    return true;
  }

  void insert(int *ptr)
  {
    if (heap_size < A.size())
    {
      A[heap_size] = ptr;
    }
    else
    {
      A.push_back(ptr);
    }
    mapping[ptr] = heap_size;
    heapUpdateKey(heap_size++);
  }

  int *heapExtractMin()
  {
    int *res = A[0];
    mapping.erase(res);
    A[0] = A[--heap_size];
    mapping[A[0]] = 0;
    minHeapify(0);
    return res;
  }

  bool isEmpty()
  {
    return heap_size == 0;
  }
};

class Solve
{
private:
  int n;

  bool search(Heap &H, unordered_map<int *, unordered_map<int, vector<int *>>> &adj, vector<vector<int>> &board, unordered_map<int *, pair<int, int>> &mapping)
  {
    if (H.isEmpty())
    {
      return true;
    }

    int *ptr = H.heapExtractMin();
    pair<int, int> &p = mapping[ptr];
    for (int k = 1; k <= n; k++)
    { 
      if (*ptr & (1 << k))
      {
        board[p.first][p.second] = k;

        vector<int *> deleted_from;
        for (int *ptr2 : adj[ptr][k])
          if (H.heapUpdateKey(ptr2, 0, k))
            deleted_from.push_back(ptr2);

        if (search(H, adj, board, mapping))
          return true;

        for (int *ptr2 : deleted_from)
          H.heapUpdateKey(ptr2, 1, k);
      }
    }
    H.insert(ptr);
    return false;
  }

public:
  Solve() {}

  Solve(vector<vector<int>> &board) : n(board.size())
  {
    int tmp = (int)ceil(sqrt(n));

    if (tmp * tmp != n)
      exit(0);

    vector<int> rows(n), columns(n), boxes(n);
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (board[i][j])
        {
          int bit = 1 << board[i][j];
          rows[i] |= bit;
          columns[j] |= bit;
          boxes[(i / tmp) * tmp + (j / tmp)] |= bit;
        }
      }
    }

    vector<vector<int>> possibilities(n, vector<int>(n));
    unordered_map<int *, pair<int, int>> mapping;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (!board[i][j])
        {
          mapping.emplace(&possibilities[i][j], make_pair(i, j));
          for (int k = 1; k <= n; k++)
          {
            int bit = 1 << k;
            if (!(rows[i] & bit) && !(columns[j] & bit) && !(boxes[(i / tmp) * tmp + (j / tmp)] & bit))
              possibilities[i][j] |= bit;
          }
        }
      }
    }

    unordered_map<int *, unordered_map<int, vector<int *>>> adj;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (possibilities[i][j])
        {
          for (int k = 0; k < n; k++)
            if (!board[i][k] && k / tmp != j / tmp)
              for (int l = 1; l <= n; l++)
                if (possibilities[i][k] & (1 << l))
                  adj[&possibilities[i][j]][l].push_back(&possibilities[i][k]);

          for (int k = 0; k < n; k++)
            if (!board[k][j] && k / tmp != i / tmp)
              for (int l = 1; l <= n; l++)
                if (possibilities[k][j] & (1 << l))
                  adj[&possibilities[i][j]][l].push_back(&possibilities[k][j]);

          int ti, tj;
          ti = (i / tmp) * tmp, tj = (j / tmp) * tmp;
          for (int tti = 0; tti < tmp; ++tti)
            for (int ttj = 0; ttj < tmp; ++ttj)
              if (!board[ti + tti][tj + ttj] && (ti + tti != i || tj + ttj != j))
                for (int l = 1; l <= n; l++)
                  if (possibilities[ti + tti][tj + ttj] & (1 << l))
                    adj[&possibilities[i][j]][l].push_back(&possibilities[ti + tti][tj + ttj]);
        }
      }
    }

    Heap H;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (possibilities[i][j])
        {
          H.insert(&possibilities[i][j]);
        }
      }
    }

    if (search(H, adj, board, mapping))
    {
      cout << board << '\n';
    }
  }
};

int n;

void progress()
{
  for (int i = 1; i < bitset_table.size(); i++)
  {
    bitset_table[i] = (i & 1) + bitset_table[i / 2];
  }
  cin >> n;
  n *= n;
  vector<vector<int>> board(n, vector<int>(n));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> board[i][j];
    }
  }
  Solve obj(board);
}
// main
int main()
{
    // Written by Shyn_
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    ll nt = 1;
    // cin >> nt;
    for (; nt--;)
    {
        progress();
    }
}
/** LeSonnn_ **/
/** LCG **/

