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


int n;
vector<int> A;
int ans = 0;
vector<vector<int>> used;

void dfs(int day, int money, int cnt)
{
    if(day == n) 
    {
        ans = max(ans, money);
        return;
    }
    if(used[day][cnt] > money) return;
    used[day][cnt] = money;
    int k = money / A[day];
    dfs(day + 1, money - k * A[day], cnt + k);
    dfs(day + 1, money, cnt);
    if(cnt > 0)
    {
        dfs(day + 1, money + cnt * A[day], 0);
    }
}

void solve()
{
    cin >> n;
    A.resize(n);
    used.resize(n + 1, vector<int>(1000, 0));
    for(int i = 0; i < n; i++) cin >> A[i];
    dfs(0, 1000, 0);
    cout << ans << endl;
}

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
