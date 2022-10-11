#include <bits/stdc++.h>
using namespace std;

const int N = 20, MXCOOR = 4005;
struct P {
    int x, y;
};
P G[N];
int slope[MXCOOR][MXCOOR], dX[N][N], dY[N][N];
int m, ans;
vector<bool> vis(N);

void rec(int d, int res) {
    if (d == m) {
        ans = max(ans, res);
        return;
    }

    int u, v;
    for (int i=0; i<m; ++i) {
        if (vis[i]) continue;
        vis[i] = true; u = i; 
        break;
    }

    for (int j=u+1; j<m; ++j) {
        if (vis[j]) continue;
        vis[j] = true; v = j;

        int tmp = res;
        int dx = dX[u][v], dy = dY[u][v];
        tmp += slope[dx][dy];        
        slope[dx][dy]++;
        rec(d+2, tmp);
        slope[dx][dy]--;
        vis[j] = false;
    }
    vis[u] = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m;
    for (int i=0; i<m; ++i) cin >> G[i].x >> G[i].y;
    for (int i=0; i<m; ++i) {
        for (int j=i+1; j<m; ++j) {
            int dx = G[i].x - G[j].x;
            int dy = G[i].y - G[j].y;
            int GCD = __gcd(dx, dy);
            dx /= GCD; dy /= GCD;
            dx += 2000; dy += 2000; // make coor. positive
            dX[i][j] = dx;
            dY[i][j] = dy;
        }
    }

    rec(0, 0);
    cout << ans << '\n';
    return 0;
}