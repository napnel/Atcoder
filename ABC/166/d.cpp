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

template<typename type> vector<type> divisor(type n)
{
    vector<type> res;
    for(type i = 1; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            res.push_back(i);
            if(i * i != n) res.push_back(n / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

void solve()
{
    ll x; cin >> x;
    vector<ll> divisors = divisor(x); 
    ll a = 1;
    while(true)
    {
        for(auto& num : divisors)
        {
            ll b = a - x / num;
            if((ll)pow(a, 5) - (ll)pow(b, 5) == x)
            {
                cout << a << " " << b << endl;
                return;
            }
        }
        a++;
    }
}

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}