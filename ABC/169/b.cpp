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
    Int n; cin >> n;
    vector<Int> A(n);
    bool ok = true;
    for(int i = 0; i < n; i++)
    {
        cin >> A[i];
        if(A[i] == 0)
        {
            ok = false;
        }
    }
    Int ans = 1;
    if(ok == false)
    {
        cout << 0 << endl;
        return;
    }
    for(int i = 0; i < n; i++)
    {
        if(A[i] == 0)
        {
            cout << 0 << endl;
            return;
        }
        if(ans > (Int)1e18 / A[i])
        {
            cout << -1 << endl;
            return;
        }
        ans *= A[i];
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
