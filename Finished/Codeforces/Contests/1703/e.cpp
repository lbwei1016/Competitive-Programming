#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

struct P {
    int x, y;
};

void solve() {
    int n; cin >> n;
    vector<string> G(n);
    for (int i=0; i<n; ++i) {
        cin >> G[i];
    }

    // vector<P> pos = {
    //     {0, 0},
    //     {0, n-1},
    //     {n-1, n-1},
    //     {n-1, 0}
    // };
    vector<P> pos(4);
    ll res = 0;
    for (int i=n-1, r=n-1; i>0; i-=2, --r) {
        pos[0] = {n-1-r, n-1-r};
        pos[1] = {n-1-r, r};
        pos[2] = {r, r};
        pos[3] = {r, n-1-r};
        for (int j=0; j<i; ++j) {
            int cnt = 0;
            for (int k=0; k<4; ++k) {
                cnt += G[pos[k].x][pos[k].y] - '0';
                pos[k].x += dx[k];
                pos[k].y += dy[k];
            }
            res += min(cnt, 4-cnt);
        }
    }
    cout << res << '\n';
}

int main() {
    io;
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
/*
a b f
c d t
e r h

f t h
b d r
a c e

h r e
t d c
f b a

a b c
d e d
c b a

c d a
b e b
a d c

a == c; b == d

a b c d
e f g h
h g f e
d c b a

d h e a
c g f b
b f g c
a e h d

a == d; 
h == b; 3,1 2,4 1,1 4,3
c == e
f == g
*/