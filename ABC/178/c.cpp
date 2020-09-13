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
using modint = ModInt<MOD>;

template<typename T> struct Combination
{
    vector<T> fact, rfact, inv;
    Combination(int n) : fact(n + 1), rfact(n + 1), inv(n + 1)
    {
        fact[0] = fact[1] = 1;
        rfact[0] = rfact[1] = 1;
        inv[1] = 1;
        for(int i = 2; i < n + 1; i++)
        {
            fact[i] = fact[i - 1] * i % MOD;
            inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
            rfact[i] = rfact[i - 1] * inv[i] % MOD;
        }
    }
    T C(int n, int k)
    {
        if(n < k) return 0;
        if(n < 0 or k < 0) return 0;
        return fact[n] * (rfact[k] * rfact[n - k] % MOD) % MOD;
    }
};

void solve()
{
    Int n; cin >> n;
    Combination<Int> comb(n);
    modint a = 10;
    modint b = 9;
    modint c = 8;
    a = a.pow(n);
    b = b.pow(n);
    b *= 2;
    c = c.pow(n);
    modint ans = a - b + c; 
    cout << ans << endl;
}

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
