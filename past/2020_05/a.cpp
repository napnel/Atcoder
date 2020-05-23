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
#include <cctype>
#include <cstdio>
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

char to_lower(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
    {
        ch += 'a' - 'A';
    }
    return ch;
}

void solve()
{
    string s, t; cin >> s >> t;
    if(s == t)
    {
        cout << "same" << endl;
        return;
    }
    for(int i = 0; i < s.size(); i++)
    {
        s[i] = to_lower(s[i]);
        t[i] = to_lower(t[i]);
   }
   if(s == t)
   {
       cout << "case-insensitive" << endl;
       return;
   }
   cout << "different" << endl;
}

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
