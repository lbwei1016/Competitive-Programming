#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int N = 105;
int n, m;
char G[N][N];
int dx[] = {1, 0, -1, 0, 1, 1, -1, -1}, 
    dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

int cnt;

void dfs(int x, int y) {
    for (int i=0; i<8; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (0<=nx && nx<n && 0<=ny && ny<=m && G[nx][ny] == '#') {
            G[nx][ny] = '.';
            dfs(nx, ny);
        }
    }
}

void solve() {
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            if (G[i][j] == '#') {
                dfs(i, j);
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
}

int main() {
    io;
    cin >> n >> m;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            cin >> G[i][j];
        }
    }    
    solve();
    return 0;
}