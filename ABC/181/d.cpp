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

bool canCreate(const string &target, map<char, int> mp)
{
    for(const char &ch : target)
    {
        if(mp[ch] == 0)
        {
            return false;
        }
        mp[ch] -= 1;
    }
    return true;
}

void solve()
{
    string s; cin >> s;
    map<char, int> mp;
    for(int i = 0; i < s.size(); i++)
    {
        mp[s[i]]++;
    }

    bool isOkay = false;
    vector<int> candidate;
    for(int i = 100; i <= 999; i++)
    {
        if(i % 8 == 0)
        {
            candidate.push_back(i);
        }
    }
    if(s.size() >= 3)
    {
        for(const int &v : candidate)
        {
            string t = to_string(v);
            if(canCreate(t, mp))
            {
                isOkay = true;
                break;
            }
        }
    }
    else if(s.size() == 1) {
        if(s == "8") isOkay = true;
    }
    else {
        assert(s.size() == 2);
        int v = stoi(s);
        if(v % 8 == 0) isOkay = true;
        reverse(s.begin(), s.end());
        v = stoi(s);
        if(v % 8 == 0) isOkay = true;
    }
    cout << (isOkay ? "Yes" : "No") << endl;
    return;
}

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
