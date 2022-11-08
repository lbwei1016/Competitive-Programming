#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int N = 1005;
int n, cnt; 
char G[N][N];
int res[N], vis[N];

void dfs(int at) {
    vis[at] = 1;
    res[++cnt] = at;
    for (int i=0; i<n; ++i) {
        if (!vis[i] && G[at][i] == '1') {
            dfs(i);
        }
    }
}

int main() {
    io;
    cin >> n;
    for (int i=0; i<n; ++i) for (int j=0; j<n; ++j)
        cin >> G[i][j];
    
    dfs(0);
    if (cnt != n) {
        cout << "impossible\n";
        return 0;
    }
    for (int i=n; i>0; --i) {
        cout << res[i] << ' ';
    }
    cout << '\n';
    return 0;
}