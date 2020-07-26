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


bool dfs(vector<int> v, int k)
{
    if(k < 0) return false;
    bool ok = true;
    for(int i = 0; i < 2; i++)
    {
        if(v[i] >= v[i + 1]) ok = false;
    }
    if(ok) return true;
    bool res = false;
    for(int i = 0; i < v.size(); i++)
    {
        vector<int> tmp = v;
        tmp[i] *= 2;
        res |= dfs(tmp, k - 1);
    }
    return res;
}

void solve()
{
    vector<int> v(3);
    for(int i = 0; i < 3; i++) cin >> v[i];
    int k; cin >> k;
    cout << (dfs(v, k) ? "Yes" : "No") << endl;
}

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
