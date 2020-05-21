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
using ll = long long;
const int INF = 1<<30;
const int MOD = (int)1e9 + 7;
const int MAX_N = (int)1e5 + 5;
#define debug(x) cout << #x << ": " << x << endl
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2>& p) { os << p.first << " " << p.second; return os; }
template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) { for(int i = 0; i < (int) v.size(); i++) os << v[i] << (i + 1 != v.size() ? " " : ""); return os; }

void solve()
{
    int n; cin >> n;
    string s; cin >> s;
    set<string> st;
    string command = "ABXY";
    for(int i = 0; i < command.size(); i++)
    {
        for(int j = 0; j < command.size(); j++)
        {
            string tmp = "";
            tmp += command[i];
            tmp += command[j];
            st.insert(tmp);
        }
    }
    // for(int i = 0; i < n - 1; i++)
    // {
    //     string t = s.substr(i, 2);
    //     st.insert(t);
    // }
    int ans = n;
    for(const auto &x : st)
    {
        for(const auto &y : st)
        {
            if(x == y) continue;
            vector<int> dp(n + 1, 0);
            for(int i = 1; i <= n; i++) dp[i] = i;
            for(int i = 2; i <= n; i++)
            {
                dp[i] = min(dp[i], dp[i - 1] + 1);
                if((s.substr(i - 2, 2) == x || s.substr(i - 2, 2) == y))
                {
                    dp[i] = min(dp[i], dp[i - 2] + 1);
                }
            }
            ans = min(ans, dp[n]);
        }
    }
    cout << ans << endl;
}

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}