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
ostream &operator<<(ostream &os, const vector<T> &v) { for(Int i = 0; i < (Int) v.size(); i++) os << v[i] << (i + 1 != v.size() ? " " : ""); return os; }

Int N, K;

void make_group(const vector<Int> &P, vector<vector<Int>> &G)
{
    vector<Int> used(N, 0);
    for(Int i = 0; i < N; i++)
    {
        Int s = i;
        if(used[s]) continue;
        vector<Int> tmp;
        while (s < N)
        {
            if (used[s]) break;
            used[s] = 1;
            tmp.push_back(s);
            s = P[s];
        }
        G.push_back(tmp);
    }
}

void solve()
{
    cin >> N >> K;

    vector<Int> P(N), C(N);
    for(Int i = 0; i < N; i++)
    {
        cin >> P[i];
        P[i]--;
    }

    for(Int i = 0; i < N; i++) cin >> C[i];

    vector<vector<Int>> G;
    make_group(P, G);

    Int ans = *max_element(C.begin(), C.end());

    for(const vector<Int> &p : G)
    {
        Int value = 0;
        Int n = (Int)p.size();
        for(Int i = 0; i < n; i++) value += C[p[i]];

        for(Int s = 0; s < n; s++)
        {
            Int score = 0;
            Int k = K;
            if(k > 2 * n && value + C[s] > 0)
            {
                score += (k / n - 1) * (value + C[s]);
            }
            k %= 2 * n;
            for(Int i = 1; i <= k; i++)
            {
                score += C[p[(s + i) % n]];
                ans = max(ans, score);
            }
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
