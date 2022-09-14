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

#include <iostream>
#include <vector>
#include <functional>
using namespace std;

Int N;
vector<Int> A;

void solve()
{
    cin >> N;
    A.resize(N);
    vector<Int> sum(N + 1, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        sum[i + 1] = sum[i] + A[i];
    }
    sort(sum.begin(), sum.end());
    // debug(sum);
    map<Int, Int> mp;
    for (int i = 0; i < N + 1; i++)
    {
        mp[sum[i]]++;
    }
    Int ans = 0;
    for (const auto &p : mp)
    {
        Int cnt = p.second;
        ans += (cnt * (cnt - 1)) / 2;
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
