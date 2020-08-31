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

map<Int, Int> prime_factor(Int N, const vector<Int> &is_prime)
{
    map<Int, Int> result;
    while(N > 1)
    {
        // N = x * p(=is_prime[N]) 
        result[is_prime[N]]++;
        N = N / is_prime[N];
    }
    return result;
}

void solve()
{
    Int N; cin >> N;
    vector<Int> A(N);
    for(Int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    vector<Int> is_prime = eratosthenes(*max_element(A.begin(), A.end()) + 1);

    vector<map<Int, Int>> buff;
    map<Int, Int> mp;
    for(Int i = 0; i < N; i++)
    {
        map<Int, Int> tmp = prime_factor(A[i], is_prime);
        for(const auto &x : tmp)
        {
            mp[x.first] += x.second;
        }
        buff.push_back(tmp);
    }

    bool ok = true;

    for(Int i = 0; i < N; i++)
    {
        if(ok == false) break;
        for(const auto &x : buff[i])
        {
            mp[x.first] -= x.second;
        }

        for(const auto &x : buff[i])
        {
            if(mp[x.first] > 0)
            {
                ok = false;
                break;
            }
        }
    }

    if(ok)
    {
        cout << "pairwise coprime" << endl;
        return;
    }

    Int v = A.front();
    for(Int i = 0; i < N; i++)
    {
        v = gcd(v, A[i]);
    }
    if(v == 1)
    {
        cout << "setwise coprime" << endl;
        return;
    }
    cout << "not coprime" << endl;
}

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
