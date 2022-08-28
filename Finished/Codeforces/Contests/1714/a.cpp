#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

void solve() {
    int n, H, M;
    cin >> n >> H >> M;
    vector<pair<int, int>> v(n);
    for (int i=0; i<n; ++i) {
        int a, b; cin >> a >> b;
        v[i] = {a, b};
    }
    sort(v.begin(), v.end());
    int resh, resm;
    auto it = lower_bound(v.begin(), v.end(), make_pair(H, M));
    if (it == v.end()) {
        auto beg = *v.begin();
        resh = beg.first + 24 - H;
        resm = beg.second - M;
    }
    else {
        resh = it->first - H;
        resm = it->second - M;
    }
    if (resm >= 60) {
        resh += resm / 60;
        resm %= 60;
    }
    else if (resm < 0) {
        resh--;
        resm += 60;
    }
    cout << resh << ' ' << resm << '\n';
}

int main() {
    io;
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}