#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <cassert>
#include <queue>
#include <map>
#include <set>
using namespace std;
using Int = int64_t;
const Int INF = 1 << 30;
const Int MOD = (Int)1e9 + 7;
const Int MAX_N = 2 * (Int)1e5 + 5;
#define debug(x) cout << #x << ": " << x << endl
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    os << p.first << " " << p.second;
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    for (int i = 0; i < (int)v.size(); i++)
        os << v[i] << (i + 1 != v.size() ? " " : "");
    return os;
}

template <typename T>
class RMQ
{
private:
    vector<T> node;
    int N = 1;

public:
    RMQ() = default;
    RMQ(int sz)
    {
        while (N < sz)
            N *= 2;
        node.assign(2 * N - 1, INF);
    }
    void update(int k, T x)
    {
        k += N - 1;
        node[k] = x;
        while (k > 0)
        {
            k = (k - 1) / 2;
            node[k] = min(node[2 * k + 1], node[2 * k + 2]);
        }
    }
    T query(int s, int t, int k, int l, int r)
    {
        if (r <= s or t <= l)
            return INF;
        if (s <= l and r <= t)
            return node[k];
        int mid = (l + r) / 2;
        T a = query(s, t, 2 * k + 1, l, mid);
        T b = query(s, t, 2 * k + 2, mid, r);
        return min(a, b);
    }
    T query(int s, int t) { return query(s, t, 0, 0, N); }
};

using P = pair<int, int>;
template <typename Monoid>
struct SegmentTree
{
    using F = function<Monoid(Monoid, Monoid)>;

    int sz;
    vector<Monoid> seg;

    const F f;
    const Monoid M1;

    SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1)
    {
        sz = 1;
        while (sz < n)
            sz <<= 1;
        seg.assign(2 * sz, M1);
    }

    void set(int k, const Monoid &x)
    {
        seg[k + sz] = x;
    }

    void build()
    {
        for (int k = sz - 1; k > 0; k--)
        {
            seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
        }
    }

    void update(int k, const Monoid &x)
    {
        k += sz;
        seg[k] = x;
        while (k >>= 1)
        {
            seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
        }
    }

    Monoid query(int a, int b)
    {
        Monoid L = M1, R = M1;
        for (a += sz, b += sz; a < b; a >>= 1, b >>= 1)
        {
            if (a & 1)
                L = f(L, seg[a++]);
            if (b & 1)
                R = f(seg[--b], R);
        }
        return f(L, R);
    }

    Monoid operator[](const int &k) const
    {
        return seg[k + sz];
    }

    template <typename C>
    int find_subtree(int a, const C &check, Monoid &M, bool type)
    {
        while (a < sz)
        {
            Monoid nxt = type ? f(seg[2 * a + type], M) : f(M, seg[2 * a + type]);
            if (check(nxt))
                a = 2 * a + type;
            else
                M = nxt, a = 2 * a + 1 - type;
        }
        return a - sz;
    }

    template <typename C>
    int find_first(int a, const C &check)
    {
        Monoid L = M1;
        if (a <= 0)
        {
            if (check(f(L, seg[1])))
                return find_subtree(1, check, L, false);
            return -1;
        }
        int b = sz;
        for (a += sz, b += sz; a < b; a >>= 1, b >>= 1)
        {
            if (a & 1)
            {
                Monoid nxt = f(L, seg[a]);
                if (check(nxt))
                    return find_subtree(a, check, L, false);
                L = nxt;
                ++a;
            }
        }
        return -1;
    }

    template <typename C>
    int find_last(int b, const C &check)
    {
        Monoid R = M1;
        if (b >= sz)
        {
            if (check(f(seg[1], R)))
                return find_subtree(1, check, R, true);
            return -1;
        }
        int a = sz;
        for (b += sz; a < b; a >>= 1, b >>= 1)
        {
            if (b & 1)
            {
                Monoid nxt = f(seg[--b], R);
                if (check(nxt))
                    return find_subtree(b, check, R, true);
                R = nxt;
            }
        }
        return -1;
    }
};

int N, Q;
void solve()
{
    cin >> N >> Q;
    vector<set<P>> st(MAX_N);
    vector<P> place(N);
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        b--;
        st[b].insert(make_pair(-a, i));
        place[i] = make_pair(b, -a); // 幼児iはbにいる
    }

    // 各集合の最大値が保存されている
    SegmentTree<int> high_coder(MAX_N, [](int a, int b) { return min(a, b); }, INF);
    for (int i = 0; i < MAX_N; i++)
    {
        int max_rate = -st[i].begin()->first;
        if (max_rate == 0)
            continue;
        high_coder.update(i, max_rate);
    }

    for (int i = 0; i < Q; i++)
    {
        int id, next_where;
        cin >> id >> next_where;
        id--;
        next_where--;
        int now_where = place[id].first;
        int rate = place[id].second;
        st[now_where].erase(make_pair(rate, id));
        st[next_where].insert(make_pair(rate, id));

        if(st[now_where].empty())
        {
            high_coder.update(now_where, INF);
        }
        else
        {
            high_coder.update(now_where, -st[now_where].begin()->first);
        }
        high_coder.update(next_where, -st[next_where].begin()->first);

        cout << high_coder.query(0, MAX_N) << "\n";
        place[id] = make_pair(next_where, rate);
    }
}

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
