#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

int mod;

void print(int h, int w, int plus) {
    vector<vector<char>> G(h, vector<char>(w, '#'));
    if (plus > 0)
        cout << h + 1 << ' ' << w << '\n';
    else 
        cout << h << ' ' << w << '\n';
    // printf("%d %d %d\n", h, w, plus);
    if (plus > 0) {
        for (int i=0; i<w; ++i) {
            if (i < plus) cout << '#';
            else cout << '.';
        }
        cout << '\n';
    }
    for (int i=0; i<h; ++i) {
        for (int j=0; j<w; ++j) 
            cout << G[i][j];
        cout << '\n';
    }
    cout << "------------------------------------\n";
}

void calc(ll h, ll w, ll plus) {
    ll res = 0;
    cout << h << ' ' << w << '\n';
    ll dh = h - plus, dw = w - plus;
    res += 2LL * ((dh + 1) + (dw + 1));
    res %= mod;
    res += ((dh + 1) * dh + (dw + 1) * dw);
    res %= mod;
    if (h != w) res = 2 * res % mod;
    cout << res << '\n';
}

int main() {
    // io;
    int t, u;
    cin >> t >> u;
    if (u == 2) cin >> mod;
    while (t--) {
        int n; cin >> n;
        int sq = sqrt(n), plus = n - sq * sq;
        if (sq * sq < n) {
            if ((sq + 1) * sq < n) {
                plus -= sq;
                if (u == 1) print(sq + 1, sq, plus);
                else {
                    cout << 4 * (sq + 1) << ' ';
                    calc(sq + 1, sq, plus);
                }
            }
            else if ((sq + 1) * sq == n) {
                if (u == 1) print(sq + 1, sq, 0);
                else cout << 2 * (2*sq + 1) << ' ' << 2 % mod << '\n';
            }
            else {
                if (u == 1) print(sq, sq, plus);
                else {
                    cout << 2 * (2*sq + 1) << ' ';
                    calc(sq, sq, plus);
                }
            }
        }
        else {
            if (u == 1) print(sq, sq, 0);
            else cout << 4 * sq << ' ' << 1 % mod << '\n';
        }
    }
    return 0;
}