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

Int N, M;

void solve()
{
    cin >> N >> M;
    map<Int, Int> tbit;
    vector<Int> moneies(N);
    for(int i = 0; i < M; i++)
    {
        int a, b; cin >> a >> b;
        moneies[i] = a;
        for(int j = 0; j < b; j++)
        {
            int c; cin >> c;
            c--;
            tbit[i] |= (1<<c);
        }
    }
    Int t = 0;
    Int finished_bit = (1<<N) - 1;
    Int ans = 0;
    while(t != finished_bit)
    {
        // 最も費用効果が高い鍵を選ぶ
        Int min_key_index = -1;
        Int min_value = INF;
        for(const auto &key : tbit)
        {
            if(key.second == 0) continue;
            // debug(key.second);
            Int key_index = key.first;
            Int flag_cnt = __builtin_popcount(key.second);
            Int value = moneies[key_index] * flag_cnt; // 鍵の価値はお金×開けられる宝箱の個数
            if(value < min_value)
            {
                min_value = value;
                min_key_index = key_index;
            }
        }
        if(min_key_index == -1)
        {
            cout << -1 << endl;
            return;
        }
        debug(min_key_index);

        // 選んだ鍵に応じて他の鍵の効果を更新する
        Int mask = tbit[min_key_index];
        for(auto &key : tbit)
        {
            key.second &= ~mask;
        }

        ans += moneies[min_key_index];
        t |= mask;
        debug(t);
        cout << endl;
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
