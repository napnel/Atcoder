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
const Int INF = 1 << 30;
const Int MOD = (Int)1e9 + 7;
const Int MAX_N = (Int)1e5 + 5;
#define debug(x) cout << #x << ": " << x << endl
#define debug2(x, y) cout << #x << ": " << x << ", " << #y << ": " << y << endl;
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    os << p.first << " " << p.second;
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    for (int i = 0; i < (int)v.size(); i++)
        os << v[i] << (i + 1 != v.size() ? " " : "");
    return os;
}

void solve()
{
    string S;
    cin >> S;

    map<char, int> m;

    for (int i = 0; i < (int)S.size(); i++)
    {
        m[S[i]]++;
    }

    vector<int> eights;
    for (int i = 104; i < 1000; i += 8)
    {
        eights.push_back(i);
    }
    // debug(eights);

    bool can_create = false;
    if (S.size() == 1 && S[0] == '8')
        can_create = true;
    else if (S.size() == 2)
    {
        if (stoi(S) % 8 == 0)
            can_create = true;
        reverse(S.begin(), S.end());
        if (stoi(S) % 8 == 0)
            can_create = true;
    }
    else
    {
        for (int i = 0; i < eights.size(); i++)
        {

            string s = to_string(eights[i]);
            map<char, int> m2 = m;

            bool all_contain = true;
            for (const char &ch : s)
            {
                if (m2[ch] == 0)
                    all_contain = false;
                else
                    m2[ch]--;
            }
            // for (const auto &p : m2)
            // {
            //     debug(p.first);
            //     debug2(p.second, m[p.first]);
            //     if (m[p.first] < p.second)
            //         all_contain = false;
            //     debug(all_contain);
            // }
            // cout << endl;

            if (all_contain)
                can_create = true;
        }
    }

    cout << (can_create ? "Yes" : "No") << endl;
}

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
