#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int N = 11, INF = 1e9 + 7;
struct P {
    int col, eqid;
};
int n, k, m;
vector<int> Pa, tar, Eq;
int dist[1 << N][N];
// int mask = 0xffffffff;

int bfs(int st) {
    queue<P> que;
    que.push(P{st, 0});
    memset(dist, 0x7f, sizeof(dist)); // assign INF
    dist[st][0] = 0;

    while (que.size()) {
        auto p = que.front(); que.pop();
        int col = p.col, eqid = p.eqid;
        int dis = dist[col][eqid];

        int eq = 0, cnt = 0;
        for (int i=0; i<m; ++i) {
            if ((eqid >> i) & 1) {
                eq |= Eq[i];
                ++cnt;
            }
        }

        for (auto paint: Pa) {
            int newcol = (paint & (~eq)) | (col & eq);
            if (dist[newcol][eqid] > dis + 1) {
                que.push(P{newcol, eqid});
                dist[newcol][eqid] = dis + 1;
            }
        }

        for (int i=0; i<m; ++i) {
            if (dist[col][eqid ^ (1 << i)] > dis + 1) {
                que.push(P{col, (eqid ^ (1 << i))});
                dist[col][eqid ^ (1 << i)] = dis + 1;
            }
        }
    }

    return dist[(1 << n) - 1][0] > int(2e9) ? -1 : dist[(1 << n) - 1][0];
}

int main() {
    io;
    cin >> n >> k >> m;
    tar.resize(n);
    int st = 0;
    for (int i=0; i<n; ++i) {
        cin >> tar[i];  
        // initial status (color #1)
        if (--tar[i] == 0) st |= (1 << i);
        // mask ^= (1 << i);
    }
    for (int i=0; i<k; ++i) {
        int paint = 0;
        for (int j=0; j<n; ++j) {
            if (tar[j] == i) 
                paint |= (1 << j);
        }
        Pa.push_back(paint);
    }

    for (int i=0; i<m; ++i) {
        int r; cin >> r;
        int eq = 0;
        for (int j=0; j<r; ++j) {
            int at; cin >> at;
            --at;
            eq |= (1 << at);
        }
        Eq.push_back(eq);
    }

    cout << bfs(st) << '\n';
    return 0;
}
/*
7 8 3
2 1 4 2 3 3 6
2 3 7
3 1 4 3
4 4 5 6 7
*/