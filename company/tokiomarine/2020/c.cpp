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

int n, k;
void solve()
{
    cin >> n >> k;
    vector<int> A(n);
    for(int i = 0; i < n; i++) cin >> A[i];

    while(k--)
    {
        bool is_convergence = true;
        // 左右からimos法を行う
        vector<int> imos1(n, 0), imos2(n, 0);
        for (int i = 0; i < n; i++)
        {
            imos1[i]++;
            if(i + A[i] + 1 < n)
            {
                imos1[i + A[i] + 1]--;
            }
        }
        for(int i = 1; i < n; i++)
        {
            imos1[i] += imos1[i - 1];
        }

        for(int i = n - 1; i >= 0; i--)
        {
            if(A[i] == 0 || i - 1 < 0) continue;
            imos2[i - 1]++;
            if(i - A[i] - 1 >= 0)
            {
                imos2[i - A[i] - 1]--;
            }
        }
        for(int i = n - 2; i >= 0; i--)
        {
            imos2[i] += imos2[i + 1];
        }
        vector<int> B(n);
        for(int i = 0; i < n; i++)
        {
            B[i] = imos1[i] + imos2[i];
            if(B[i] != n) is_convergence = false;
        }
        A = B;
        if(is_convergence) break;
    }
    for(int i = 0; i < n; i++) cout << A[i] << " "; cout << endl;
}

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
