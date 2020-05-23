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

int N, M, Q;
vector<vector<int>> G;
vector<int> color;
void paint(const int &pos)
{
    for(int i = 0; i < G[pos].size(); i++)
    {
        int v = G[pos][i];
        color[v] = color[pos];
    }
}
void solve()
{
    cin >> N >> M >> Q;
    G.resize(N);
    color.resize(N);
    for(int i = 0; i < M; i++)
    {
        int u, v; cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i = 0; i < N; i++) cin >> color[i];
    while(Q--)
    {
        int flag; cin >> flag;
        if(flag == 1) // 起動する
        {
            int x; cin >> x; x--;
            cout << color[x] << endl;
            paint(x);
        }
        if(flag == 2) // 上書きする
        {
            int x, y; cin >> x >> y;
            x--;
            cout << color[x] << endl;
            color[x] = y;
        }
    }
}

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
