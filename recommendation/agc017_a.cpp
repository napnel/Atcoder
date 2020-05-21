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

template<typename T> struct Combination
{
    vector<T> fact, rfact, inv;
    Combination(ll n) : fact(n + 1), rfact(n + 1), inv(n + 1)
    {
        fact[0] = fact[1] = 1;
        rfact[0] = rfact[1] = 1;
        inv[1] = 1;
        for(ll i = 2; i < n + 1; i++)
        {
            fact[i] = fact[i - 1] * i % MOD;
            inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
            rfact[i] = rfact[i - 1] * inv[i] % MOD;
        }
    }
    T C(ll n, ll k)
    {
        if(n < k) return 0;
        if(n < 0 or k < 0) return 0;
        return fact[n] * (rfact[k] * rfact[n - k] % MOD) % MOD;
    }
};

void solve()
{
    ll n, p; cin >> n >> p;
    ll A = 0, B = 0;
    for(ll i = 0; i < n; i++)
    {
        ll a; cin >> a;
        if(a & 1) A++;
        else B++;
    }
    Combination<ll> comb(n + 1);
    // ll ans = 0;
    ll ans = pow(2LL, B);
    ll sum = 0;
    if(p)
    {
        for(ll i = 1; i <= A; i += 2)
        {
            sum += comb.C(A, i);
            // for(ll j = 0; j <= B; j++)
            // {
            //     ans += comb.C(A, i) * comb.C(B, j);
            // }
        }
    }
    else
    {
        for(ll i = 0; i <= A; i += 2)
        {
            sum += comb.C(A, i);
            // for(ll j = 0; j <= B; j++)
            // {
            //     ans += comb.C(A, i) * comb.C(B, j);
            // }
        }
    }
    // cout << ans << endl;
    cout << ans * sum << endl;
    
}

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}