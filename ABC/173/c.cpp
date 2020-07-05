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

int h, w, k;
vector<string> table;
void solve()
{
    cin >> h >> w >> k;
    table.resize(h);
    for(int i = 0; i < h; i++)
    {
        cin >> table[i];
    }
    int ans = 0;
    for(int bit_h = 0; bit_h < (1<<h); bit_h++)
    {
        for(int bit_w = 0; bit_w < (1<<w); bit_w++)
        {
            vector<string> tmp = table;
            for(int i = 0; i < h; i++)
            {
                for(int j = 0; j < w; j++)
                {
                    if(bit_h & (1<<i) || bit_w & (1<<j))
                    {
                        tmp[i][j] = '.';
                    }
                }
            }
            int cnt = 0;
            for(int i = 0; i < h; i++)
            {
                for(int j = 0; j < w; j++)
                {
                    if(tmp[i][j] == '#') cnt++;
                }
            }
            if(cnt == k) ans++;
        }
    }
    cout << ans << endl;
}

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
