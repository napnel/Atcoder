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
    Int N;
    cin >> N;
    vector<Int> A(N);
    // vector<Int> dp(200, 0);
    // map<Int, set<Int>> dp;
    vector<vector<Int>> dp(200);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        A[i] %= 200;
        dp[A[i]].push_back(i);
        // dp[A[i]]++;
    }

    while (true)
    {
        bool update = false;

        for (int i = 0; i < 200; i++)
        {
            if (dp[i].size())
                continue;

            for (int j = 0; j < 200; j++)
            {
                for (int k = 0; k < 200; k++)
                {
                    if (dp[j].size() == 0 || dp[k].size() == 0)
                        continue;
                    if (j == k && dp[j].size() < 1)
                        continue;

                    if ((j + k) % 200 == i)
                    {
                        for (const auto &x : dp[j])
                            dp[i].push_back(x);

                        for (const auto &x : dp[k])
                            dp[i].push_back(x);

                        update = true;
                    }
                }
            }
        }

        if (!update)
            break;
    }

    for (int i = 0; i < 200; i++)
    {
        cout << i << ": ";
        for (int s : dp[i])
            cout << s << " ";

        cout << endl;
    }

    // for (int i = 0; i < (int)A.size(); i++)
    // {
    //     int sum_a = A[i];
    // }
}

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
