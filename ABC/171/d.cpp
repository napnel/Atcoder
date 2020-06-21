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
ostream &operator<<(ostream &os, const vector<T> &v) { for(Int i = 0; i < (Int) v.size(); i++) os << v[i] << (i + 1 != v.size() ? " " : ""); return os; }

void solve()
{
    Int n; cin >> n;
    map<Int, Int> mp;
    Int sum = 0;
    for(Int i = 0; i < n; i++)
    {
        Int x; cin >> x;
        mp[x]++;
        sum += x;
    }
    Int q; cin >> q;
    for(Int i = 0; i < q; i++)
    {
        Int b, c; cin >> b >> c;
        Int cnt = mp[b];
        sum -= cnt * b;
        mp[b] = 0;
        mp[c] += cnt;
        sum += cnt * c;
        cout << sum << "\n";
    }
}

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
