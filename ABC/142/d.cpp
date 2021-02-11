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

map<Int, Int> prime_factor(Int N)
{
    map<Int, Int> result;
    for(Int i = 2; i * i <= N; i++)
    {
        while(N % i == 0)
        {
            result[i]++;
            N /= i;
        }
    }
    if(N != 1) result[N] = 1;
    return result;
}

void solve()
{
    Int A, B; cin >> A >> B;
    map<Int, Int> factor_A = prime_factor(A);
    map<Int, Int> factor_B = prime_factor(B);

    set<Int> common_divisors;
    common_divisors.insert(1);
    for(auto x : factor_A)
    {
        if(B % x.first == 0)
            common_divisors.insert(x.first);
    }
    for(auto x : factor_B)
    {
        if(A % x.first == 0)
            common_divisors.insert(x.first);
    }
    cout << common_divisors.size()<< endl;
}

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
