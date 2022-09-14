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
    Int N, M;
    cin >> N >> M;
    vector<Int> X(N + 1, 0);
    for (int i = 0; i < N; i++)
        cin >> X[i + 1];

    vector<Int> Y(N + 1, 0);
    for (int i = 0; i < M; i++)
    {
        Int c, y;
        cin >> c >> y;
        Y[c] = y;
    }

    vector<vector<Int>> dp(N + 1, vector<Int>(N + 1, -INF));
    dp[0][0] = 0;
    for (int i = 1; i <= N; i++)
    {
        Int prev_max_value = -INF;
        for (int j = 0; j <= N; j++)
            prev_max_value = max(prev_max_value, dp[i - 1][j]);
        for (int j = 0; j <= N; j++)
        {
            if (j > i)
                break;

            if (j > 0)
            {
                dp[i][j] = dp[i - 1][j - 1] + X[i] + Y[j];
            }
            else
            {
                dp[i][j] = prev_max_value;
            }
        }
    }
    // debug(X);
    // debug(Y);
    // for (int i = 0; i <= N; i++)
    // {
    //     debug(dp[i]);
    // }
    Int ans = 0;
    for (int j = 0; j <= N; j++)
    {
        ans = max(ans, dp[N][j]);
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
