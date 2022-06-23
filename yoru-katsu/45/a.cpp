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

void solve()
{
    Int n; cin >> n;
    vector<Int> A(n);
    for(int i = 0; i < n; i++) cin >> A[i];

    Int first_max = 0;
    Int second_max = 0;
    for(int i = 0; i < n; i++)
    {
        if(first_max < A[i])
        {
            first_max = A[i];
        }
        else if(second_max < A[i])
        {
            second_max = A[i];
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(first_max == A[i])
        {
            cout << second_max << endl;
        }
        else
        {
            cout << first_max << endl;
        }
        
    }
}

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
