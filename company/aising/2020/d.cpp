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
#include <bitset>
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

Int N;
string X;
Int popcount(const string& s)
{
    Int res = 0;
    for(int i = 0; i < s.size(); i++) if(s[i] == '1') res++;
    return res;
}

Int func(string s)
{
    int count = popcount(s);
    int valid_digit = log2(count) + 1;
    debug(valid_digit);
    string t = s.substr(0, valid_digit + 1);
    Int num = stoll(t) % count;
    string u = to_string(num);
    debug(u);
    if(num == 0) return 0;
    func(u);
}

void solve()
{
    cin >> N >> X;
    reverse(X.begin(), X.end());
    int count = popcount(X);
    for(int i = N - 1; i >= 0; i--)
    {
        int cnt = count;
        if(X[i] == '1')
        {
            cnt--;
            X[i] = '0';
        }
        else
        {
            cnt++;
            X[i] = '1';
        }
        debug(X); 
        debug(cnt);
        int valid_digit = (int)(log2(cnt)) + 1;
        debug(valid_digit);
        string s = X.substr(0, valid_digit);
        Int num = 0;
        for(int i = 0; i < valid_digit; i++) num += pow(2, i);
        debug(num);
        num %= cnt;
        debug(num);
    }
}

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
