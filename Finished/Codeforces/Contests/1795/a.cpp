#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

bool solve() {
    int x, y; cin >> x >> y;
    string a, b;
    cin >> a >> b;
    int la = 0, lb = 0;
    int cnta = 0, cntb = 0;
    for (auto it = ++a.begin(); it != a.end(); ++it) {
        // int off = 0;
        auto itt = it;
        bool in = false;
        while (it != a.end() && *it == *next(it, -1)) {
            ++it;
            ++cnta;
            in = true;
        }
        la = max(la, int(it - itt + 1));
        if (in) --it;
    }

    for (auto it = ++b.begin(); it != b.end(); ++it) {
        // int off = 0;
        auto itt = it;
        bool in = false;
        while (it != b.end() && *it == *next(it, -1)) {
            ++it;
            ++cntb;
            in = true;
        }
        lb = max(lb, int(it - itt + 1));
        if (in) --it;
    }

    if (la <= 1 && lb <= 1) return true;
    if (la > 1 && lb > 1) return false;
    if (cnta > 1 || cntb > 1) return false;
    if (la > 2 || lb > 2) return false;
    if (*a.rbegin() == *b.rbegin()) return false;

    return true;
}

int main() {
    io;
    int tt; cin >> tt;
    while (tt--) {
        if (solve()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}