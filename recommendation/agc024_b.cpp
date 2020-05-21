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
#include <list>
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
    vector<int> p(n);
    for(int i = 0; i < n; i++) cin >> p[i];
    using P = pair<int, int>;
    vector<P> v;
    for(int i = 0; i < n; i++) v.push_back(P(p[i], i));
    sort(v.begin(), v.end());
    int ans = n;
    int max_cnt = 1;
    int cnt = 1;
    for(int i = 1; i < n; i++)
    {
        if(v[i - 1].second < v[i].second)
        {
            cnt++;
        }
        else cnt = 1;
        max_cnt = max(max_cnt, cnt);
    }
    cout << ans - max_cnt << endl;
}

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}