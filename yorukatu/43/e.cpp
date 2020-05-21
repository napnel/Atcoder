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
    vector<P> say;
    for(int i = 0; i < n; i++)
    {
        int a; cin >> a;
        for(int j = 0; j < a; j++)
        {
            int x, y; cin >> x >> y;
            say.push_back(P(x - 1, y));
        }
    }
    int ans = 0;
    for(int bit = 0; bit < (1<<n); bit++)
    {
        bool ok = true;
        for(int i = 0; i < n; i++) cout << (bit & (1<<i)); cout << endl;
        int tmp_bit = bit;
        for(int i = 0; i < n; i++)
        {
            if(tmp_bit & (1<<i))
            {
                int target = say[i].first;
                int flag = (tmp_bit & (1 << target) ? 1 : 0);
                if (flag != say[i].second) ok = false; // 矛盾
                if(say[i].second) tmp_bit |= (1<<target);
            }
        }
        debug(ok);
        int cnt = __builtin_popcount(bit);
        if(ok) ans = max(ans, cnt);
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