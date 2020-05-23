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
ostream &operator<<(ostream &os, const vector<T> &v) { for(Int i = 0; i < (Int) v.size(); i++) os << v[i] << (i + 1 != v.size() ? " " : ""); return os; }

const Int shift = 500;
const Int H = 750;
const Int W = 750;
const Int dy[] = {1, 0, -1, 0, 1, 1};
const Int dx[] = {0, 1, 0, -1, 1, -1};
Int N, X, Y;
using P = pair<Int, Int>;
using PP = pair<Int, P>;
vector<vector<Int>> visited;

Int bfs()
{
    priority_queue<PP, vector<PP>, greater<PP>> que;
    que.push(PP(0, P(shift, shift)));
    visited[shift][shift] = 0;
    while(!que.empty())
    {
        PP p = que.top(); que.pop();
        Int x = p.second.first;
        Int y = p.second.second;
        // if(x == X && y == Y)
        // {
        //     return visited[X][Y];
        // }
        for(Int i = 0; i < 6; i++)
        {
            Int nx = x + dx[i];
            Int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= W || ny >= H) continue;
            // Int dist = abs(Y - ny) * abs(Y - ny) + abs(X - nx) * abs(X - nx);
            Int dist = abs(Y - ny) + abs(X - nx);
            if(visited[nx][ny] > visited[x][y])
            {
                visited[nx][ny] = visited[x][y] + 1;
                que.push(PP(dist, P(nx, ny)));
            }
        }
    }
    if(visited[X][Y] == INF) return -1;
    return visited[X][Y];
}

void solve()
{
    cin >> N >> X >> Y;
    X += shift;
    Y += shift;
    visited.resize(H, vector<Int>(W, INF));
    for(Int i = 0; i < N; i++)
    {
        Int x, y; cin >> x >> y;
        x += shift;
        y += shift;
        visited[x][y] = -1;
    }
    cout << bfs() << endl;
}

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
