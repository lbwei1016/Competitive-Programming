#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

const int INF = 2e9 + 7;

int main() {
    io;
    int n, m;
    cin >> n >> m;
    multiset<int> tel, bon;
    for (int i=0; i<n; ++i) {
        int x; cin >> x;
        tel.insert(x);
    }

    vector<int> ntel(m), nbon(m);
    for (int i=0; i<m; ++i) {
        int x; cin >> x;
        auto it = tel.insert(x);
        int d1 = INF, d2 = INF;
        if (it != tel.begin()) {
            d1 = x - *next(it, -1);
        }
        if (it != tel.end()) {
            d2 = *next(it, 1) - x;
        }
        ntel[i] = min(d1, d2);

        bon.insert(x);
    }

    int at = 0;
    for (auto x: bon) {
        auto it = bon.find(x);
        int d1 = INF, d2 = INF;
        if (it != bon.begin()) {
            d1 = x - *next(it, -1);
        }
        if (it != bon.end()) {
            d2 = *next(it, 1) - x;
        }
        nbon[at++] = min(d1, d2);
    }

    ll res = 0;
    int head;
    for (int i=0; i<m; ++i) {
        if (nbon[i] < ntel[i]) {
            if (head = -1)
            res += nbon[i];
        }
        else {

        }
    }
    return 0;
}