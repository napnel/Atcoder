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
#define debug2(x, y) cout << #x << ": " << x << " " << #y << ": " << y << endl;
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2>& p) { os << p.first << " " << p.second; return os; }
template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) { for(ll i = 0; i < (ll) v.size(); i++) os << v[i] << (i + 1 != v.size() ? " " : ""); return os; }

vector<ll> B(10);
bool cmp_less(const string &x, const string &y)
{
    if(x.size() > y.size()) return true;
    if(x.size() < y.size()) return false;
    ll idx_x = 0, idx_y = 0;
    const int n = x.size();
    for(int i = 0; i < n; i++)
    {
        int a = x[i] - '0';
        int b = y[i] - '0';
        for(int j = 0; j < B.size(); j++)
        {
            if(a == B[j]) idx_x = j;
            if(b == B[j]) idx_y = j;
        }
        if(idx_x > idx_y) return true;
        if(idx_x < idx_y) return false;
    }
    return true;
}

void solve()
{
    for(ll i = 0; i < 10; i++) cin >> B[i];
    ll n; cin >> n;
    vector<ll> A(n);
    for(ll i = 0; i < n; i++) cin >> A[i];
    for(ll i = 0; i < n; i++)
    {
        string s = to_string(A[i]);
        int idx = i;
        for(ll j = i + 1; j < n; j++)
        {
            string t = to_string(A[j]);
            if(cmp_less(s, t)) // s > t
            {
                s = t;
                idx = j;
            }
        }
        swap(A[i], A[idx]);
    }
    for(const auto &ans : A) cout << ans << endl;
}

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}