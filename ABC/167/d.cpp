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
const ll INF = 1<<30;
const ll MOD = (ll)1e9 + 7;
const ll MAX_N = (ll)1e5 + 5;
#define debug(x) cout << #x << ": " << x << endl
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2>& p) { os << p.first << " " << p.second; return os; }
template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) { for(ll i = 0; i < (ll) v.size(); i++) os << v[i] << (i + 1 != v.size() ? " " : ""); return os; }

vector<ll> loop_path;
vector<ll> used;
ll first_loop_pos = -1;
ll cnt = 0;
void get_loop_path(ll pos, const vector<vector<ll>> &G)
{
    if(used[pos] == 3)
    {
        first_loop_pos = pos;
        return;
    }
    used[pos]++;
    loop_path.push_back(pos);
    for(ll i = 0; i < G[pos].size(); i++)
    {
        ll u = G[pos][i];
        get_loop_path(u, G);
    }
}

void get_dist(ll pos, const vector<vector<ll>> &G)
{
    if(pos == first_loop_pos) return;
    for(ll i = 0; i < G[pos].size(); i++)
    {
        ll u = G[pos][i];
        cnt++;
        get_dist(u, G);
    }
}


void dfs(ll pos, const vector<vector<ll>> &G, ll k)
{
    if(k == 0)
    {
        cout << pos + 1 << endl;
        return;
    }
    for(ll i = 0; i < G[pos].size(); i++)
    {
        ll u = G[pos][i];
        dfs(u, G, k - 1);
    }
}

void solve()
{
    ll n, k; cin >> n >> k;
    vector<vector<ll>> G(n);
    for(ll i = 0; i < n; i++)
    {
        ll a; cin >> a;
        a--;
        G[i].push_back(a);
    }

    if(k <= 1e7)
    {
        dfs(0, G, k);
        return;
    }

    used.resize(n, 0);
    get_loop_path(0, G);

    vector<ll> target_path;
    for(ll i = 0; i < loop_path.size(); i++)
    {
        if(used[loop_path[i]] >= 2)
        {
            target_path.push_back(loop_path[i]);
        }
    }

    get_dist(0, G);
    k -= cnt;
    k %= (ll)target_path.size();
    dfs(first_loop_pos, G, k);
}

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}