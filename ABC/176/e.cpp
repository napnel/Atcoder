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
using P = pair<int, int>;
const Int INF = 1<<30;
const Int MOD = (Int)1e9 + 7;
const Int MAX_N = (Int)1e5 + 5;
#define debug(x) cout << #x << ": " << x << endl
#define debug2(x, y) cout << #x << ": " << x << ", " << #y << ": " << y << endl;
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2>& p) { os << p.first << " " << p.second; return os; }
template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) { for(int i = 0; i < (int) v.size(); i++) os << v[i] << (i + 1 != v.size() ? " " : ""); return os; }

void solve()
{
    int H, W, M; cin >> H >> W >> M;
    vector<int> y(H, 0), x(W, 0);

    set<P> st;

    for(int i = 0; i < M; i++)
    {
        int h, w; cin >> h >> w;
        h--, w--;
        y[h]++;
        x[w]++;
        st.insert(P(h, w));
    }

    priority_queue<P> py, px;
    for(int i = 0; i < H; i++) py.push(P(y[i], i));
    for(int i = 0; i < W; i++) px.push(P(x[i], i));

    int ans = 0;

    P target_h = py.top();

    for(int i = 0; i < W; i++)
    {
        int cnt = target_h.first + x[i];
        if(st.count(P(target_h.second, i))) cnt--;
        ans = max(ans, cnt);
    }

    P target_w = px.top();

    for(int i = 0; i < H; i++)
    {
        int cnt = target_w.first + y[i];
        if(st.count(P(i, target_w.second))) cnt--;
        ans = max(ans, cnt);
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
