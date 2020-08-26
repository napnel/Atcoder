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
using PP = pair<Int, P>;
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

vector<int> wy, wx;

void bfs(int sy, int sx)
{
    priority_queue<PP, vector<PP>, greater<PP>> que;
    que.push(PP(0, P(sy, sx)));
    visited[sy][sx] = 0;

    while(!que.empty())
    {
        PP p = que.top(); que.pop();
        int y = p.second.first;
        int x = p.second.second;

        if(y == gy && x == gx) return;

        // 1. move
        for(int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
            if(board[ny][nx] == '#') continue;
            if(p.first < visited[ny][nx])
            {
                visited[ny][nx] = p.first;
                que.push(PP(p.first, P(ny, nx)));
            }
        }
 
        // 2. warp
        for(int i = 0; i < wx.size(); i++)
        {
            int ny = y + wy[i];
            int nx = x + wx[i];
            if (ny < 0 || nx < 0 || ny >= h || nx >= w)
                continue;
            if (board[ny][nx] == '#')
                continue;
            if (p.first + 1 < visited[ny][nx])
            {
                visited[ny][nx] = p.first + 1;
                que.push(PP(p.first + 1, P(ny, nx)));
            }
        }
    }
}
 
void solve()
{
    cin >> h >> w;
    board.resize(h);
    visited.resize(h, vector<Int>(w, INF));
    Int sy, sx;
    cin >> sy >> sx;
    sy--, sx--;

    cin >> gy >> gx;
    gy--, gx--;

    for(Int i = 0; i < h; i++)
    {
        cin >> board[i];
    }

    for(int i = -2; i <= 2; i++)
    {
        for(int j = -2; j <= 2; j++)
        {
            if(i == 0 && j == 0) continue;
            for(int k = 0; k < 4; k++)
            {
                if(i == dy[k] && j == dx[k]) continue;
                wy.push_back(i);
                wx.push_back(j);
            }
        }
    }


    bfs(sy, sx);

    Int ans = visited[gy][gx];

    // for(int i = 0; i < h; i++)
    // {
    //     for(int j = 0; j < w; j++) cout << setw(2) << visited[i][j] << " ";
    //     cout << endl;
    // }

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