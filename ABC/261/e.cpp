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
#include <bitset>
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

int calc(int base, int t, int a)
{
    if (t == 1)
    {
        base &= a;
    }
    if (t == 2)
    {
        base |= a;
    }
    if (t == 3)
    {
        base ^= a;
    }
    return base;
}

void check()
{
    for (int a = 0; a <= 16; a++)
    {
        cout << "---------" << endl;
        for (int b = 0; b <= 16; b++)
        {
            if (a != b)
                continue;
            bitset<8> a1(a), b1(b);
            debug(a1);
            debug(b1);
            cout << "-------" << endl;
            bitset<8> bs1(a & b), bs2(a | b), bs3(a ^ b);
            debug(bs1);
            debug(bs2);
            debug(bs3);
        }
    }
}

void solve()
{
    check();
    Int N, C;
    cin >> N >> C;
    vector<pair<int, int>> operators;
    for (int i = 0; i < N; i++)
    {
        int t, a;
        cin >> t >> a;
        operators.push_back(make_pair(t, a));
    }

    int ans = C;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            ans = calc(ans, operators[j].first, operators[j].second);
            bitset<8> bs(ans);
            debug(ans);
            debug(bs);
        }
        cout << ans << endl;
    }
}

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
