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
#include <deque>
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
    for(int i = 0; i < n; i++) cin >> A[i];
    sort(A.rbegin(), A.rend());
    Int ans = 0;
    int nn = n / 2;
    if(n % 2) nn++;
    vector<Int> v;
    v.push_back(A.front());
    for (int i = 0; i < nn - 1; i++)
    {
        Int a = v.front();
        Int b = v.back();
        ans += min(a, b);
        v.push_back(A[i + 1]);
    }
    v.push_back(v.front());
    vector<Int> tmp;
    for(int i = 0; i < (int)v.size() - 1; i++)
    {
        tmp.push_back(min(v[i], v[i + 1]));
    }
    sort(tmp.rbegin(), tmp.rend());
    for(int i = 0; i < n - nn; i++) ans += tmp[i];
    cout << ans << endl;
}

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
