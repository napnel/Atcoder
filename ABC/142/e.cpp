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
    Int N, M;
    cin >> N >> M;
    vector<Int> tmask(M, 0);
    vector<Int> moneies(M);
    for(int i = 0; i < M; i++)
    {
        Int a, b; cin >> a >> b;
        moneies[i] = a;
        for(int j = 0; j < b; j++)
        {
            Int c; cin >> c;
            c--;
            tmask[i] |= (1<<c);
        }
    }
    Int digit = 1<<N;
    vector<Int> dp(digit, INF);
    dp[0] = 0;
    for(int S = 0; S < digit; S++)
    {
        for(int i = 0; i < M; i++)
        {
            Int T = S | tmask[i];
            Int cost = dp[S] + moneies[i];
            dp[T] = min(dp[T], cost);
        }
    }
    Int ans = dp.back();
    if(ans == INF) ans = -1;
    cout << ans << endl;
}

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
