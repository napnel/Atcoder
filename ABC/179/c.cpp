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
    return res;
}
map<Int, Int> prime_factor(Int N, const vector<Int> &is_prime)
{
    map<Int, Int> result;
    while(N > 1)
    {
        result[is_prime[N]]++;
        N = N / is_prime[N];
    }
    return result;
}

vector<Int> eratosthenes(const Int &N)
{
    vector<Int> is_prime(N + 1);
    for(int i = 0; i < is_prime.size(); i++) is_prime[i] = i;
    is_prime[1] = 0;

    for(Int i = 2; i * i <= N; i++)
    {
        if(is_prime[i] != i) continue;
        for(Int j = 2 * i; j <= N; j += i)
        {
            is_prime[j] = min(is_prime[j], i);
        }
    }
    return is_prime;
}

void solve()
{
    Int n; cin >> n;
    vector<Int> is_prime = eratosthenes(n);
    Int ans = 0;
    for(Int c = 1; c <= n; c++)
    {
        map<Int, Int> mp = prime_factor(n - c, is_prime);
        Int cnt = 1;
        for(const auto &x : mp)
        {
            cnt *= (x.second + 1);
        }
        ans += cnt;
    }
    cout << ans - 1 << "\n";

}

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
