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

Int calc_in(Int B, Int C)
{
    if(B == 0) return 0;
    Int res = 0;
    Int cnt = C / 3;
    if(cnt > B)
    {
        res += 2 * B + 1;
    }
    else
    {
        res += 2 * cnt;
    }
    return res;
}

Int calc_out(Int B, Int C)
{
    Int cnt = C / 3;
    Int res = 2 * cnt;
    if(C % 3 == 2) res++;
    return res;
}

void solve()
{
    Int B, C; cin >> B >> C;
    Int ans = 1;
    if(B != 0)
    {
        C--;
        ans++;
    }
    ans += calc_in(B, C) + calc_out(B, C);
    cout << ans << endl;
}

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
