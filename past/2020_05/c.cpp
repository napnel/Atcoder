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
#define debug(x) cout << #x << ": " << x << endl
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2>& p) { os << p.first << " " << p.second; return os; }
template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) { for(int i = 0; i < (int) v.size(); i++) os << v[i] << (i + 1 != v.size() ? " " : ""); return os; }

void solve()
{
    Int A, R, N; cin >> A >> R >> N;
    const Int MAX_N = (Int)1e9;
    if(A > MAX_N)
    {
        cout << "large" << endl;
        assert(true);
        return;
    }
    if(R == 1)
    {
        cout << A << endl;
        return;
    }
    Int ans = A;
    for(int i = 1; i <= N - 1; i++)
    {
        ans *= R;
        if(ans > MAX_N)
        {
            cout << "large" << endl;
            return;
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
