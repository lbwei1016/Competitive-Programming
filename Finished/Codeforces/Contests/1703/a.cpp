#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

void solve() {
    string s; cin >> s;
    for (int i=0; i<3; ++i) {
        if (s[i] == 'y') s[i] = 'Y';
        else if (s[i] == 'e') s[i] = 'E';
        else if (s[i] == 's') s[i] = 'S';
    }
    string t = "YES";
    cout << (s==t ? "YES\n" : "NO\n");
}

int main() {
    io;
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}