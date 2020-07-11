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

Int func(Int n)
{
    Int res = 0;
    for(Int x = 1; x <= sqrt(n); x++)
    {
        if(x * x > n) break;
        for(Int y = 1; y <= sqrt(n); y++)
        {
            if(x * x + y * y > n) break;
            for(Int z = 1; z <= sqrt(n); z++)
            {
                Int tmp = x * x + y * y + z * z + x * y + y * z + z * x;
                if(tmp > n) break;
                if(tmp == n) res++;
            }
        }
    }
    return res;
}

void solve()
{
    Int n; cin >> n;
    for(Int i = 1; i <= n; i++)
    {
        cout << func(i) << "\n";
    }
}

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
