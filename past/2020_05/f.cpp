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
const Int INF = 1<<30;
const Int MOD = (Int)1e9 + 7;
const Int MAX_N = (Int)1e5 + 5;
#define debug(x) cout << #x << ": " << x << endl
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2>& p) { os << p.first << " " << p.second; return os; }
template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) { for(int i = 0; i < (int) v.size(); i++) os << v[i] << (i + 1 != v.size() ? " " : ""); return os; }

using P = pair<int, char>;
map<P, int> mp;
void solve()
{
    int n; cin >> n;
    vector<string> table;
    for(int i = 0; i < n; i++)
    {
        string s; cin >> s;
        table.push_back(s);
    }
    if(n == 1)
    {
        cout << table[0] << endl;
        return;
    }

    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mp[P(i, table[i][j])]++;
        }
    }
    string ans = "";
    bool ok = true;
    for(int i = 0; i < n / 2; i++) // 上半分だけみる
    {
        int down = n - i - 1;
        bool flag = false;
        for(int j = 0; j < n; j++)
        {
            if(mp[P(down, table[i][j])] > 0)
            {
                ans += table[i][j];
                flag = true;
                break;
            }
        }
        if(flag == false) ok = false;
    }
    if(ans == "" || ok == false) // 構成できない
    {
        cout << -1 << endl;
        return;
    }
    if(n % 2 == 0)
    {
        string tmp = ans;
        reverse(tmp.begin(), tmp.end());
        ans += tmp;
    }
    else
    {
        char center = table[n / 2][0];
        string tmp = ans;
        reverse(tmp.begin(), tmp.end());
        ans += center + tmp;
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
