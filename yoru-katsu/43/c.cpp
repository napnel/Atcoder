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
using ll = long long;
const int INF = 1<<30;
const int MOD = (int)1e9 + 7;
const int MAX_N = (int)1e5 + 5;
#define debug(x) cout << #x << ": " << x << endl
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2>& p) { os << p.first << " " << p.second; return os; }
template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) { for(int i = 0; i < (int) v.size(); i++) os << v[i] << (i + 1 != v.size() ? " " : ""); return os; }

void solve()
{
    int n; cin >> n;
    vector<int> A(n + 2);
    A[0] = A[n + 1] = 0;
    int sum = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> A[i];
    }
    vector<int> diff;
    for(int i = 0; i <= n; i++)
    {
        sum += abs(A[i] - A[i + 1]);
        diff.push_back(abs(A[i] - A[i + 1]));
    }
    debug(sum);
    for(int i = 1; i <= n; i++)
    {
        int ans = sum;
        int a = A[i - 1];
        int b = A[i + 1];
        int d = abs(a - b);
        ans -= diff[i - 1] + diff[i] - d;
        cout << ans << endl;
    }
}

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}