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

template<typename type> vector<type> divisor(type n)
{
    vector<type> res;
    for(type i = 1; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            res.push_back(i);
            if(i * i != n) res.push_back(n / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}


void solve()
{
    int n; cin >> n;
    vector<int> A(n);
    for(int i = 0; i < n; i++) cin >> A[i];
    sort(A.begin(), A.end());
    set<int> st[n];
    for(int i = 0; i < n; i++)
    {
        vector<int> divisors = divisor(A[i]);
        for(const auto &x : divisors) st[i].insert(x);
    }
    set<int> B;
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        bool is_ok = true;
        for(const auto &x : st[i])
        {
            if(B.count(x)) is_ok = false;
        }
        if(is_ok)
        {
            if(i + 1 < n && A[i + 1] != A[i])
            {
                ans++;
            }
            else if(i == n - 1)
            {
                ans++;
            }
        }
        B.insert(A[i]);
    }
    cout << ans << "\n";
}

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
