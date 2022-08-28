#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

struct coor {
    int x, y;
    coor() {}
    coor(int _x, int _y): x(_x), y(_y) {}
    bool operator<(coor c) const {
        return x == c.x ? y < c.y : x < c.x;
    }
};

int dx[] = {-1, 0, 0, 1}, dy[] = {0, 1, -1, 0};
map<char, int> MP = {{'N', 0}, {'E', 1}, {'W', 2}, {'S', 3}};

coor solve() {
    int n, R, C, sr, sc;
    cin >> n >> R >> C >> sr >> sc;
    map<coor, vector<coor>> mp;

    vector<coor> tmp = {{sr-1, sc}, {sr, sc+1}, {sr, sc-1}, {sr+1, sc}};
    mp.insert(make_pair(coor{sr, sc}, tmp));
    int x = sr, y = sc;
    for (int i=0; i<n; ++i) {
        char c; cin >> c;
        int dir = MP[c];

        auto bor = mp[coor{x, y}][dir];
        int nx = bor.x, ny = bor.y;
        auto it = mp.find({nx, ny});

        if (it == mp.end()) {
            vector<coor> tmp(4);
            for (int j=0; j<4; ++j) {
                int mx = nx + dx[j], my = ny + dy[j];
                auto nei = mp.find(coor{mx, my});
                if (nei != mp.end()) {
                    tmp[j] = nei->second[j];
                }
                else {
                    tmp[j] = coor{mx, my};
                }
            }
            it = mp.insert(it, make_pair(coor{nx, ny}, tmp));
        }

        // 更新所有四方向邊界 (對左邊界更新右、對下邊界更新上...)
        for (int j=0; j<4; ++j) {
            int px = mp[bor][j].x + dx[3-j];
            int py = mp[bor][j].y + dy[3-j];
            auto bor_it = mp.find(coor{px, py});
            // assert(bor_it != mp.end());
            bor_it->second[3-j] = it->second[3-j];
        }
        x = nx, y = ny;
    }
    return coor{x, y};
}

int main() {
    io;
    int tt; cin >> tt;
    for (int i=1; i<=tt; ++i) {
        coor res = solve();
        cout << "Case #" << i << ": " << res.x << ' ' << res.y << '\n';
    }
    return 0;
}