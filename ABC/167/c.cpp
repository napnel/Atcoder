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
    int n, m, x; cin >> n >> m >> x;
    vector<int> C(n);
    vector<vector<int>> A(n, vector<int>(m));
    for(int i = 0; i < n; i++)
    {
        cin >> C[i];
        for(int j = 0; j < m; j++) cin >> A[i][j];
    }

    int ans = INF;
    for(int bit = 0; bit < (1<<n); bit++)
    {
        vector<int> v;
        vector<int> score(m, 0);
        for(int i = 0; i < n; i++)
        {
            if(bit & (1<<i))
            {
                v.push_back(i);
            }
        }
        int sum = 0;
        for(int i = 0; i < v.size(); i++)
        {
            for(int j = 0; j < m; j++)
            {
                score[j] += A[v[i]][j];
            }
            sum += C[v[i]];
        }
        bool ok = true;
        for(int i = 0; i < score.size(); i++)
        {
            if(score[i] < x) ok = false;
        }
        if(ok)
        {
            ans = min(ans, sum);
        }
    }
    if(ans == INF)
    {
        cout << -1 << endl;
        return;
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