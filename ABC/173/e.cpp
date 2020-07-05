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
template <int mod>
struct ModInt
{
    int x;
    ModInt() : x(0) {}
    ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

    ModInt &operator+=(const ModInt &p)
    {
        if ((x += p.x) >= mod)
        {
            x -= mod;
        }
        return *this;
    }
    ModInt &operator-=(const ModInt &p)
    {
        if ((x += mod - p.x) >= mod)
        {
            x -= mod;
        }
        return *this;
    }
    ModInt &operator*=(const ModInt &p)
    {
        x = (int)(1LL * x * p.x % mod);
        return *this;
    }
    ModInt &operator/=(const ModInt &p)
    {
        *this *= p.inverse();
        return *this;
    }

    ModInt operator-() const { return ModInt(-x); }
    ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }
    ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }
    ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }
    ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }

    bool operator==(const ModInt &p) const { return x == p.x; }
    bool operator!=(const ModInt &p) const { return x != p.x; }

    ModInt inverse() const
    {
        int a = x, b = mod, u = 1, v = 0;
        while (b > 0)
        {
            int t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return ModInt(u);
    }

    ModInt pow(int64_t n) const
    {
        ModInt res(1), mul(x);
        while (n > 0)
        {
            if (n & 1)
            {
                res *= mul;
            }
            mul *= mul;
            n >>= 1;
        }
        return res;
    }

    friend ostream &operator<<(ostream &os, const ModInt &p) { return os << p.x; }
    friend istream &operator>>(istream &is, ModInt &a)
    {
        int64_t t;
        is >> t;
        a = ModInt<mod>(t);
        return (is);
    }

    static int get_mod() { return mod; }
};

/*
最大値が正か負になるか、まず判定する必要がある。
そのあと、それぞれのパターンの処理を書けば解けそう。
*/
using modint = ModInt<MOD>;
void solve()
{
    Int N, k; cin >> N >> k;
    priority_queue<Int> A;
    priority_queue<Int, vector<Int>, greater<Int>> B;
    vector<Int> v;
    int zero = 0;
    for(int i = 0; i < N; i++)
    {
        Int x; cin >> x;
        if(x != 0) v.push_back(x);
        if(x == 0) zero++;
        else if(x > 0) A.push(x);
        else B.push(x);
    }

    if(zero && N == k)
    {
        cout << 0 << endl;
        return;
    }
    if(N == k || N - zero == k)
    {
        modint ans = 1;
        for(int i = 0; i < v.size(); i++) ans *= v[i];
        cout << ans << endl;
        return;
    }

    modint ans = 1; 
    if(k % 2)
    {
        if(!A.empty())
        {
            Int p = A.top();
            A.pop();
            ans *= p;
            k--;
        }
        else
        {
            priority_queue<Int, vector<Int>, greater<Int>> tmp = B;
            while(true)
            {
                Int n = tmp.top(); tmp.pop();
                if(tmp.empty())
                {
                    ans *= n;
                    k--;
                    break;
                }
            }
        }
    }
    cout << "test" << endl;
    while(k)
    {
        vector<Int> p;
        Int positive = 1;
        for(int i = 0; i < 2; i++)
        {
            if(A.empty()) continue;
            positive *= A.top();
            p.push_back(A.top());
            A.pop();
        }

        vector<Int> n;
        Int negative = 1;
        for(int i = 0; i < 2; i++)
        {
            if(B.empty()) continue;
            negative *= B.top();
            n.push_back(B.top());
            B.pop();
        }

        if(positive > negative)
        {
            debug(positive);
            ans *= positive;
            for(int i = 0; i < n.size(); i++) B.push(n[i]);
        }
        else
        {
            debug(negative);
            ans *= negative;
            for(int i = 0; i < p.size(); i++) A.push(p[i]);
        }
        k -= 2;
        debug(ans);
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
