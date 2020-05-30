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

Int n;
vector<Int> A;

void solve()
{
    cin >> n;
    A.resize(n + 1);
    for(Int i = 0; i <= n; i++) cin >> A[i];

    vector<Int> cnt(n + 1, 0);
    cnt[n] = A[n];
    Int sum = 0;
    for(int i = n - 1; i >= 0; i--)
    {
        cnt[i] += cnt[i + 1];
        cnt[i] += A[i];
        sum += cnt[i];
    }
    cout << sum << endl;

    // ２分木にする
    int parent_cnt = 1;
    for(int i = 0; i < n; i++)
    {
        if(cnt[i] > parent_cnt)
        {
            sum -= cnt[i] - parent_cnt;
            cnt[i] = parent_cnt;
        }
        parent_cnt = pow(2, cnt[i]) - A[i];
        if(parent_cnt <= 0)
        {
            cout << -1 << endl;
            return;
        }
    }
    cout << sum << endl;
}

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
