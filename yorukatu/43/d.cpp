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
using P = pair<int, int>;

void solve()
{
    int n; cin >> n;
    vector<vector<P>> say(n);
    for(int i = 0; i < n; i++)
    {
        int a; cin >> a;
        for(int j = 0; j < a; j++)
        {
            int x, y; cin >> x >> y;
            x--;
            say[i].push_back(P(x, y));
        }
    }
    int ans = 0;
    for(int bit = 0; bit < (1<<n); bit++)
    {
        bool ok = true;
        for(int i = 0; i < n; i++)
        {
            if(!(bit & (1<<i))) continue;
            for(const auto &s : say[i])
            {
                int target = s.first;
                int flag = s.second;
                if(flag && !(bit & (1<<target))) ok = false;
                else if(bit & (1<<target)) ok = false;
            }
        }
        if(ok)
        {
            // for(int i = 0; i < n; i++) cout << (bit & (1<<i)); cout << endl;
            ans = max(ans, __builtin_popcount(bit));
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