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
    int n, m; cin >> n >> m;
    vector<int> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];
    vector<int> G[n];
    for(int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }


    vector<int> not_ok(n, -1);
    for(int i = 0; i < n; i++)
    {
        if(not_ok[i] == 0) continue;
        bool good = true;
        vector<int> tmp;
        
        for(int j = 0; j < G[i].size(); j++)
        {
            int v = G[i][j];
            if(h[i] <= h[v]) good = false;
            tmp.push_back(v);
        }
        if(good)
        {
            not_ok[i] = 1;
            for(int j = 0; j < tmp.size(); j++)
            {
                not_ok[tmp[j]] = 0;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(not_ok[i] == 1) ans++;
    }
    cout << ans << endl;
}

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}