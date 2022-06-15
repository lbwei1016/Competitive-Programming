#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

int dx[] = {1, -1, -1, 1};
int dy[] = {1, -1, 1, -1};

int main() {
    io;
    int t;
    cin >> t;
    while (t--) {
        char G[8][8];
        int pre = 0;
        bool good = false;
        for (int i=0; i<8; ++i) {
            int d[2] = {-1, -1};
            for (int j=0, cnt=0; j<8; ++j) {
                cin >> G[i][j];
                if (G[i][j] == '#') d[cnt++] = j;
            }
            if (good) continue;
            if (pre != 0 && d[1] == -1) {
                cout << i+1 << ' ' << d[0]+1 << '\n';
                good = true;
                continue;
            }
            if (d[1] != -1)
                pre = d[1] - d[0];
        }
    }
    return 0;
}