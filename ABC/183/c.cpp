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

int N, K;
int dfs(int v, int t, vector<int> &used, const vector<vector<int>> &T)
{
    if(t > K) return 0;
    bool finished = true;
    for(int i = 0; i < N; i++)
    {
        if(!used[i]) finished = false;
    }
    if(finished && t == K && v == 0) return 1;

    int res = 0;
    for(int i = 0; i < N; i++)
    {
        if(i == v || used[i]) continue;
        used[i] = true;
        res += dfs(i, t + T[v][i], used, T);
        used[i] = false;
    }
    return res;
}

void solve()
{
    cin >> N >> K;
    vector<vector<int>> T(N, vector<int>(N));
    vector<int> used(N, 0);
    for(int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> T[i][j];
        }
    }
    int ans = dfs(0, 0, used, T);
    cout << ans << endl;
}

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
