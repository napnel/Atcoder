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
    for (Int i = 0; i < (Int)v.size(); i++)
        os << v[i] << (i + 1 != v.size() ? " " : "");
    return os;
}

void solve()
{
    Int n;
    cin >> n;
    vector<Int> x(n);
    for (Int i = 0; i < n; i++)
        cin >> x[i];

    double ans1 = 0;
    double ans2 = 0;
    double ans3 = 0;
    for (int i = 0; i < n; i++)
    {
        ans1 += abs(x[i]);
        ans2 += x[i] * x[i];
        ans3 = max(ans3, (double)abs(x[i]));
    }
    cout << ans1 << endl;
    cout << sqrt(ans2) << endl;
    cout << ans3 << endl;
}

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    solve();
    return 0;
}
