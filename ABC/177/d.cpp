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
using P = pair<Int, Int>;
const Int INF = 1<<30;
const Int MOD = (Int)1e9 + 7;
const Int MAX_N = (Int)1e5 + 5;
#define debug(x) cout << #x << ": " << x << endl
#define debug2(x, y) cout << #x << ": " << x << ", " << #y << ": " << y << endl;
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2>& p) { os << p.first << " " << p.second; return os; }
template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) { for(int i = 0; i < (int) v.size(); i++) os << v[i] << (i + 1 != v.size() ? " " : ""); return os; }

template <class T>
class UnionFind
{
private:
    int groups;

public:
    vector<T> data;
    UnionFind(int sz)
    {
        data.assign(sz, -1);
        this->groups = sz;
    }
    bool unite(T x, T y)
    {
        x = find(x), y = find(y);
        if (x == y)
            return (false);
        if (data[x] > data[y])
            swap(x, y);
        data[x] += data[y];
        data[y] = x;
        groups--;
        return (true);
    }
    T find(T k)
    {
        if (data[k] < 0)
            return (k);
        return (data[k] = find(data[k]));
    }
    T size(T k) { return (-data[find(k)]); }
    int getGroups() { return this->groups; }
};

void solve()
{
    Int N, M; cin >> N >> M;
    UnionFind<Int> uf(N);
    for(int i = 0; i < M; i++)
    {
        Int A, B; cin >> A >> B;
        A--, B--;
        uf.unite(A, B);
    }

    Int max_size = 0;
    for(int i = 0; i < N; i++)
    {
        max_size = max(max_size, uf.size(i));
    }

    cout << max_size << endl;
}

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
