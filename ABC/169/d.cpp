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

template<typename Type> map<Type, int > prime_factor(Type n)
{
    map<Type, int > res;
    for(Type i = 2; i * i <= n; i++)
    {
        while(n % i == 0)
        {
            res[i]++;
            n /= i;
        }
    }
    if(n != 1) res[n] = 1;
    return res;
}


void solve()
{
    Int N; cin >> N;
    map<Int, int> prime_factors = prime_factor(N);
    set<Int> st;
    for(const auto& prime_factor : prime_factors)
    {
        int num = prime_factor.second;
        Int value = prime_factor.first;
        for(int i = 0; i < num; i++)
        {
            st.insert(value);
            value *= prime_factor.first;
        }
    }
    Int ans = 0;
    for(const auto& x : st)
    {
        if(N % x != 0) continue;
        N /= x;
        if(N == 0) break;
        ans++;
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
