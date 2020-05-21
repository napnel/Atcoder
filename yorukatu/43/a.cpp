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

void solve()
{
    int a, b; cin >> a >> b;
    for(int i = 0; i <= 1e5; i++)
    {
        if(a == (int)(i * 0.08) && b == (int)(i * 0.1))
        {
            cout << "No" << endl;
            return;
        }
    }
    
}

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}