#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int MXR = 1005;
int R, C;
char G[MXR][MXR];
bool vis[MXR][MXR];

struct P { int x, y; };
vector<P> Dir = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1}
};

vector<P> mDir {
    {1, -1},
    {-1, 1},
    {1, 1},
    {-1, -1}
};

int sz;

bool dfs(P v) {
    ++sz;
    int x = v.x, y = v.y;
    vis[x][y] = true;
    bool st = true;
    vector<P> dir = Dir;
    for (int i=0; i<4; ++i) {
        auto p = Dir[i];
        int nx = x + p.x, ny = y + p.y;
        if (!(nx < 1 || nx > R || ny < 1 || ny > C)) {
            if (G[nx][ny] == '/') {
                dir.push_back(mDir[0]);
                dir.push_back(mDir[1]);
                break;
            }
            else if (G[nx][ny] == '\\') {
                dir.push_back(mDir[2]);
                dir.push_back(mDir[3]);
                break;
            }
        }
    }
    for (auto p: dir) {
        int nx = x + p.x, ny = y + p.y;
        if (nx < 1 || nx > R || ny < 1 || ny > C) st = false;
        else {
            if (G[nx][ny] != '.' || vis[nx][ny]) continue;
            st &= dfs(P{nx, ny});
        }
    }
    return st;
}

int main() {
    io;
    cin >> R >> C;
    vector<P> dot;
    dot.reserve(MXR*MXR);
    for (int i=1; i<=R; ++i) {
        for (int j=1; j<=C; ++j) {
            cin >> G[i][j];
            if (G[i][j] == '.') {
                dot.push_back(P{i, j});
            }
        }
    }

    int cnt = 0;
    for (auto p: dot) {
        if (!vis[p.x][p.y]) {
            sz = 0;
            cnt += dfs(p);
            // cout << "sz: " << sz << '\n';
        }
    }

    int rr = 0;
    for (int i=1; i<R; ++i) {
        for (int j=1; j<C; ++j) {
            if (G[i][j] == '/') {
                if (G[i][j+1] == '\\' && G[i+1][j] == '\\' && G[i+1][j+1] == '/') {
                    // ++cnt;
                    ++rr;
                }
            }
        }
    }

    // cout << cnt << '\n';

    cout << cnt + rr << '\n';
    return 0;
}