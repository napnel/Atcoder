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
    int L, R;
    cin >> L >> R;
    vector<int> l(L), r(R);
    for (int i = 0; i < L; i++)
        cin >> l[i];
    for (int i = 0; i < R; i++)
        cin >> r[i];

    // sort(l.begin(), l.end());
    // sort(r.begin(), r.end());
    int ans = 0;
    vector<int> used(R, 0);
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < R; j++)
        {
            if (used[j])
                continue;
            if (l[i] == r[j])
            {
                ans += 1;
                used[j] = 1;
                break;
            }
        }
    }
    cout << ans << endl;
}

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
