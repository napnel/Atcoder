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
    for (int i = 0; i < (int)v.size(); i++)
        os << v[i] << (i + 1 != v.size() ? " " : "");
    return os;
}

void solve()
{
    int N;
    cin >> N;
    vector<pair<int, pair<int, int>>> v;
    v.push_back(make_pair(0, make_pair(0, 0)));
    for (int i = 0; i < N; i++)
    {
        int t, x, y;
        cin >> t >> x >> y;
        v.push_back(make_pair(t, make_pair(x, y)));
    }

    bool ok = true;
    for (int i = 1; i < (int)v.size(); i++)
    {
        int prev_x = v[i - 1].second.first;
        int prev_y = v[i - 1].second.second;

        int d = abs(v[i].second.first - prev_x) + abs(v[i].second.second - prev_y);
        int delta_t = v[i].first - v[i - 1].first;

        if (d > delta_t)
            ok = false;
        else if (d < delta_t)
        {
            int remain = delta_t - d;
            if (remain % 2)
                ok = false;
        }
    }
    cout << (ok ? "Yes" : "No") << endl;
}

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
