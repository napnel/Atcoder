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

vector<Int> eratosthenes(const Int &N)
{
    vector<Int> is_prime(N + 1, 1);
    is_prime[0] = is_prime[1] = 0;
    for (Int j = 4; j <= N; j += 2)
        is_prime[j] = 0;
    for (Int i = 3; i * i <= N; i += 2)
    {
        if (is_prime[i] == 0)
            continue;
        for (Int j = 2 * i; j <= N; j += i)
        {
            is_prime[j] = 0;
        }
    }
    return is_prime;
}

void solve()
{
    int x;
    cin >> x;

    vector<Int> is_prime = eratosthenes(MAX_N);
    for (int i = x; i < MAX_N; i++)
    {
        if (is_prime[i])
        {
            cout << i << endl;
            return;
        }
    }
}

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
