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
using PP = pair<Int, P>;
const Int INF = 1 << 30;
const Int MOD = (Int)1e9 + 7;
const Int MAX_N = (Int)1e5 + 5;
#define debug(x) cout << #x << ": " << x << endl
#define debug2(x, y) cout << #x << ": " << x << ", " << #y << ": " << y << endl;
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    os << p.first << " " << p.second;
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    for (Int i = 0; i < (Int)v.size(); i++)
        os << v[i] << (i + 1 != v.size() ? " " : "");
    return os;
}

vector<PP> pos;
int ans = INF;

int calc(int from, int to)
{
    return abs(pos[to].first - pos[from].first) + abs(pos[to].second.first - pos[from].second.first) + max((Int)0, pos[to].second.second - pos[from].second.second);
}

void dfs(int now, int bit, int sum)
{
    bool isgo = false;

    for (int i = 1; i < (int)pos.size(); i++)
    {
        if (bit & (1 << i))
            continue;
        isgo = true;
        dfs(i, bit | (1 << i), sum + calc(now, i));
    }

    if (!isgo)
    {
        ans = min(ans, calc(now, 0));
    }
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        pos.push_back(PP(x, P(y, z)));
    }
    pos.push_back(pos.front());

    vector<int> used(n, 0);
    dfs(0, 0, 0);
    cout << ans << endl;
}

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    solve();
    return 0;
}
