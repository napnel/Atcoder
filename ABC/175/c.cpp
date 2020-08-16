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
const Int INF = 1<<30;
const Int MOD = (Int)1e9 + 7;
const Int MAX_N = (Int)1e5 + 5;
#define debug(x) cout << #x << ": " << x << endl
#define debug2(x, y) cout << #x << ": " << x << ", " << #y << ": " << y << endl;
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2>& p) { os << p.first << " " << p.second; return os; }
template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) { for(int i = 0; i < (int) v.size(); i++) os << v[i] << (i + 1 != v.size() ? " " : ""); return os; }

void solve()
{
    Int x, k, d;
    cin >> x >> k >> d;

    Int ans = 1e17;

    if(x > 0)
    {
        Int cnt = (x + d - 1) / d;
        if(cnt <= k)
        {
            k -= cnt;
            if(k % 2LL && k > 0)
            {
                ans = min(ans, abs(x - cnt * d + d));
            }
            else
            {
                ans = min(ans, abs(x - cnt * d));
            }
            
        }
        else // x - k * d
        {
            ans = min(ans, abs(x - k * d));
        }
        
    }
    else
    {
        Int cnt = (abs(x) + d - 1) / d;
        if(cnt <= k)
        {
            k -= cnt;
            if(k % 2LL && k > 0)
            {
                ans = min(ans, abs(x + cnt * d - d));
            }
            else
            {
                ans = min(ans, abs(x + cnt * d));
            }
        }
        else
        {
            ans = min(ans, abs(x + k * d));
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
