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
    string S, T, U;
    cin >> S >> T >> U;

    set<char> st;
    for (int i = 0; i < S.size(); i++)
        st.insert(S[i]);

    for (int i = 0; i < T.size(); i++)
        st.insert(T[i]);

    for (int i = 0; i < U.size(); i++)
        st.insert(U[i]);

    if (st.size() > 10)
    {
        cout << "UNSOLVABLE" << endl;
        return;
    }

    vector<int> mapper(10);
    for (int i = 0; i < mapper.size(); i++)
        mapper[i] = i;

    do
    {
        string n1, n2, n3;
        map<char, int> mp;
        int i = 0;
        for (const auto &ch : st)
        {
            mp[ch] = mapper[i] + '0';
            i++;
        }

        // for (auto &p : mp)
        //     debug2(p.first, p.second);

        for (int i = 0; i < S.size(); i++)
            n1 += mp[S[i]];

        for (int i = 0; i < T.size(); i++)
            n2 += mp[T[i]];

        for (int i = 0; i < U.size(); i++)
            n3 += mp[U[i]];

        // debug2(n1, n2);
        // debug(n3);

        if (n1.front() == '0' || n2.front() == '0' || n3.front() == '0')
            continue;

        Int m1 = stoll(n1);
        Int m2 = stoll(n2);
        Int m3 = stoll(n3);

        if (m1 + m2 == m3)
        {
            cout << m1 << endl;
            cout << m2 << endl;
            cout << m3 << endl;
            return;
        }

    } while (next_permutation(mapper.begin(), mapper.end()));

    cout << "UNSOLVABLE" << endl;
}

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
