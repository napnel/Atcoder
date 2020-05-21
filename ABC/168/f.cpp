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

vector<int> ans;
vector<int> visited(MAX_N, 0);
void dfs(const vector<vector<int>> &G, int pos, int pre = -1)
{
    queue<int> que;
    que.push(pos);
    while(not que.empty())
    {
        int v = que.front(); que.pop();
        visited[v] = 1;
        for(int i = 0; i < G[v].size(); i++)
        {
            int u = G[v][i];
            if(ans[u] != -1) continue;
            ans[u] = v;
            que.push(u);
        }
    }
}

void solve()
{
    int n, m; cin >> n >> m;
    vector<vector<int>> G(n);
    ans.resize(n, -1);
    for(int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    cout << "Yes" << endl;
    ans[0] = -1;
    dfs(G, 0);
    for(int i = 1; i < ans.size(); i++) cout << ans[i] + 1 << endl;
}

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}