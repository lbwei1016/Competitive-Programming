#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

struct P {
    int x, y;
    bool operator<(P p) const {
        return x == p.x ? y < p.y : x < p.x;
    }
};
int n;
int xrev = 1, yrev = 1;
P st, ed;
vector<P> err;

int main() {
    io;
    cin >> n;
    cin >> st.x >> st.y >> ed.x >> ed.y;
    if (st.x > ed.x) {
        xrev = -1;
        st.x *= -1; ed.x *= -1;
    }
    if (st.y > ed.y) {
        yrev = -1;
        st.y *= -1; ed.y *= -1;
    }
    // err.resize(n);
    for (int i=0; i<n; ++i) {
        int x, y; cin >> x >> y;
        x *= xrev; y*= yrev;
        if (st.x <= x && x <= ed.x && st.y <= y && y <= ed.y)
            err.push_back(P{x, y});
    }

    sort(err.begin(), err.end());
    vector<int> lis;
    for (auto p: err) {
        auto it = upper_bound(lis.begin(), lis.end(), p.y);
        if (it == lis.end()) lis.push_back(p.y);
        else *it = p.y;
    }

    cout << lis.size() << '\n';

    return 0;
}