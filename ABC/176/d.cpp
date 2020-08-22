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
ostream &operator<<(ostream &os, const vector<T> &v) { for(Int i = 0; i < (Int) v.size(); i++) os << v[i] << (i + 1 != v.size() ? " " : ""); return os; }
 
Int h, w;
Int gy, gx;
 
vector<string> board;
vector<vector<Int>> visited;
 
const Int dy[] = {1, 0, -1, 0};
const Int dx[] = {0, 1, 0, -1};

Int ans = INF;
Int num = 1;
 
bool bfs(Int sy, Int sx, vector<P> &pos)
{
    queue<P> que;
    visited[sy][sx] = num;
    que.push(make_pair(sy, sx));

    vector<P> tmp;
 
    while(!que.empty())
    {
        P p = que.front();
        que.pop();
 
        if(p.first == gy && p.second == gx)
        {
            return true;
        }
 
        for(Int i = 0; i < 4; i++)
        {
            Int ny = p.first + dy[i];
            Int nx = p.second + dx[i];
            if(ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
            if(board[ny][nx] == '#' || visited[ny][nx]) continue;
            visited[ny][nx] = num;
            que.push(make_pair(ny, nx));
        }
 
        for(Int i = -2; i <= 2; i++)
        {
            for(Int j = -2; j <= 2; j++)
            {
                Int ny = p.first + i;
                Int nx = p.second + j;
                if(ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
                if(board[ny][nx] == '#' || visited[ny][nx]) continue;
                tmp.push_back(make_pair(ny, nx));
            }
        }
    }

    for(int i = 0; i < (Int)tmp.size(); i++)
    {
        if(visited[tmp[i].first][tmp[i].second]) continue;
        pos.push_back(tmp[i]);
    }

    return false;
}
 
void dfs(Int sy, Int sx, Int res)
{
    vector<P> pos;
    bool ok = bfs(sy, sx, pos);

    // for(Int i = 0; i < h; i++)
    // {
    //     for(Int j = 0; j < w; j++) cout << visited[i][j] << " ";
    //     cout << endl;
    // }
    // cout << endl;

    if(ok)
    {
        ans = min(ans, res);
        return;
    }
    
    num++;

    vector<vector<int>> tmp(h, vector<int>(w));
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            tmp[i][j] = visited[i][j];
        }
    }
 
    for(Int i = 0; i < (Int)pos.size(); i++)
    {
        if(visited[pos[i].first][pos[i].second]) continue;
        dfs(pos[i].first, pos[i].second, res + 1);
    }
}
 
void solve()
{
    cin >> h >> w;
    board.resize(h);
    visited.resize(h, vector<Int>(w, 0));
    Int sy, sx;
    cin >> sy >> sx;
    sy--, sx--;
    cin >> gy >> gx;
    gy--, gx--;
    for(Int i = 0; i < h; i++)
    {
        cin >> board[i];
    }
 
    dfs(sy, sx, 0);
    if(ans == INF)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
}
 
signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}