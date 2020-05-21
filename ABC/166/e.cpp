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

void solve()
{
    ll n; cin >> n;
    vector<ll> A(n + 1);
    for(ll i = 1; i <= n; i++) cin >> A[i];
    map<ll, pair<ll, ll>> mp;
    for(ll i = 1; i <= n; i++)
    {
        ll tmp = i + A[i];
        mp[tmp].first++;
    }
    ll ans = 0;
    for(ll i = 1; i <= n; i++)
    {
        ll tmp = i - A[i];
        mp[tmp].second++;
    }
    for(auto& x : mp)
    {
        ll cnt = x.second.first * x.second.second;
        ans += cnt;
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