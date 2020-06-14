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

void solve()
{
    int x, n; cin >> x >> n;
    vector<int> p(n);
    for(int i = 0; i < n; i++) cin >> p[i];
    vector<int> v;
    for(int k = -500; k <= 500; k++)
    {
        bool is_ok = true;
        for(int i = 0; i < n; i++)
        {
            if(k == p[i]) is_ok = false;
        }
        if(is_ok == false) continue;
        v.push_back(k);
    }

    int ans = -1;
    int dist = INF;
    for(int i = 0; i < v.size(); i++)
    {
        if(abs(x - v[i]) < dist)
        {
            dist = abs(x - v[i]);
            ans = v[i];
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
