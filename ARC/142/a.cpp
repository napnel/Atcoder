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
const Int MAX_N = (Int)1e14 + 5;
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

set<Int> ans;
set<Int> used;

void rev(Int x, Int n, Int k)
{
    if (x >= 1 && x <= n && to_string(x).size() >= to_string(k).size())
        ans.insert(x);

    if (x >= MAX_N || used.count(x))
        return;

    used.insert(x);
    string s = to_string(x);
    string t = s;
    reverse(t.begin(), t.end());

    Int a = Int(std::stoll(s));
    Int b = Int(std::stoll(t));
    // debug(a);
    // debug(b);
    rev(a * 10, n, k);
    rev(a, n, k);
    rev(b, n, k);
    rev(b * 10, n, k);
}

void solve()
{
    Int N, K;
    cin >> N >> K;
    string s = to_string(K);
    string t = s;
    reverse(t.begin(), t.end());

    Int a = stoll(s);
    Int b = stoll(t);

    if (a > b)
    {
        cout << 0 << endl;
        return;
    }

    while (a <= N)
    {
        ans.insert(a);
        a *= 10;
    }
    while (b <= N)
    {
        ans.insert(b);
        b *= 10;
    }
    // for (auto x : ans)
    // cout << x << endl;
    Int cnt = Int(ans.size());
    cout << cnt << endl;
}

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
