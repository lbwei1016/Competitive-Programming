#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; ++i) cin >> a[i];
    for (int i=0; i<n; ++i) {
        int b; cin >> b;
        string s; cin >> s;
        for (int j=0; j<b; ++j) {
            if (s[j] == 'U') {
                a[i]--;
                a[i] = (10+a[i]) % 10;
            }
            else {
                a[i]++;
                a[i] %= 10;
            }
        }
    }
    for (auto x: a) {
        cout << x << ' ';
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