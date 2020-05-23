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

void solve()
{
    int n, m, q; cin >> n >> m >> q;
    vector<int> problem(m, n);
    vector<vector<int>> solved(n, vector<int>(m, 0));
    for(int i = 0; i < q; i++)
    {
        int flag; cin >> flag;
        if(flag == 1)
        {
            int x; cin >> x;
            x--;
            int sum = 0;
            for(int j = 0; j < m; j++)
            {
                if(solved[x][j]) sum += problem[j];
            }
            cout << sum << endl;
        }
        if(flag == 2)
        {
            int a, b; cin >> a >> b;
            a--, b--;
            problem[b]--;
            solved[a][b] = 1;
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
