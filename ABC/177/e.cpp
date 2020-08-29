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

vector<Int> is_prime;
void Era(Int n)
{
    is_prime.resize(n + 1);
    is_prime[0] = is_prime[1] = 0;
    is_prime[2] = 1;
    for(Int i = 3; i * i <= n; i += 2)
    {
        if(is_prime[i] == 0) continue;
        for(Int j = 2 * i; j <= n; j += i) 
        {
            is_prime[j] = 0;
        }
    }
}

vector<Int> func(Int n)
{
    vector<Int> res;
    if(n % 2 == 0) res.push_back(2);
    for(Int i = 3; i * i <= n; i += 2)
    {
        if(!is_prime[i]) continue;
        if(n % i == 0) // iはnの約数である
        {
            res.push_back(i);
            if(i * i != n) res.push_back(n / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

Int GCD(Int a, Int b)
{
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}

void solve()
{
    Int N; cin >> N;
    vector<Int> A(N);
    for(Int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    Era((Int)1e6+8);

    vector<vector<Int>> divisors;
    map<Int, Int> mp;
    for(Int i = 0; i < N; i++)
    {
        vector<Int> tmp = func(A[i]);
        for(Int j = 0; j < tmp.size(); j++)
        {
            mp[tmp[j]]++;
        }
        divisors.push_back(tmp);
    }

    bool ok = true;

    for(Int i = 0; i < N; i++)
    {
        if(ok == false) break;
        for(Int j = 0; j < divisors[i].size(); j++)
        {
            mp[divisors[i][j]]--;
        }


        for(Int j = 0; j < divisors[i].size(); j++)
        {
            Int v = divisors[i][j];
            if(mp[v] > 0)
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
        v = GCD(v, A[i]);
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
