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
    int N, M, X;
    cin >> N >> M >> X;

    vector<int> cost(N, 0);
    int l = 0;
    int r = 0;
    for (int i = 0; i < M; i++)
    {
        int a;
        cin >> a;
        if (a > X)
        {
            l++;
        }
        else
        {
            r++;
        }
    }

    int ans = min(l, r);

    cout << ans << endl;
}

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
