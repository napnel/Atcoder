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

const double PI = acos(-1);
double DegreeToRadian(double degree)
{
    return degree * PI / 180.0;
}
double RadianToDegree(double radian)
{
    return radian * 180.0 / PI;
}
void solve()
{
    cout << fixed << setprecision(10);
    double a, b, h, m; cin >> a >> b >> h >> m;
    h *= 30;
    h += 0.5 * m;
    m *= 6;
    double degree = abs(h - m);
    double rad = DegreeToRadian(degree);
    double ans = a * a + b * b - 2 * a * b * cos(rad);
    cout << sqrt(ans) << endl;
}

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}