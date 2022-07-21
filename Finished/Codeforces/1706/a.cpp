#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    string s;
    for (int i=0; i<m; ++i) s.push_back('B');
    for (int i=0; i<n; ++i) {
        cin >> a[i];
        a[i]--;
        if (a[i] < m-a[i]-1) {
            if (s[a[i]] != 'A') s[a[i]] = 'A';
            else s[m-a[i]-1] = 'A';
        }
        else {
            if (s[m-a[i]-1] != 'A') s[m-a[i]-1] = 'A';
            else s[a[i]] = 'A';
        }
    }
    cout << s + '\n';
}

int main() {
    io;
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}