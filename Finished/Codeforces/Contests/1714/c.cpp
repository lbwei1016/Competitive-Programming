#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> v;
    int cnt = 9;
    while (true) {
        if (n < 10 && n <= cnt) break;
        v.push_back(cnt);
        n -= cnt;
        cnt--;
    }
    if (n > 0)
        v.push_back(n);
    reverse(v.begin(), v.end());
    for (auto x: v) {
        cout << x;
    }
    cout << '\n';
}

int main() {
    io;
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}