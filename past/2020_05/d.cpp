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

vector<string> value = {
    "####.##.##.####", // 0
    ".#.##..#..#.###",
    "###..#####..###",
    "###..####..####",
    "#.##.####..#..#",
    "####..###..####", // 5
    "####..####.####",
    "###..#..#..#..#",
    "####.#####.####",
    "####.####..####"
};

int H = 5;
int W = 3;
void solve()
{
    int n; cin >> n;
    vector<string> table;
    for(int i = 0; i < H; i++)
    {
        string s; cin >> s;
        string t = "";
        for(int j = 0; j < s.size(); j++)
        {
            if(j % 4 == 0) continue;
            t += s[j];
        }
        table.push_back(t);
    }
    string ans = "";
    for(int k = 0; k < n; k++)
    {
        string s = "";
        for(int i = 0; i < H; i++)
        {
            for(int j = 0; j < W; j++)
            {
                s += table[i][j + W * k];
            }
        }
        for(int i = 0; i < 10; i++)
        {
            string str = value[i];
            if(str == s) ans += to_string(i);
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
