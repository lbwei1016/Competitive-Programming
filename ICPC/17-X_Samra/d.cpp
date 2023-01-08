#include <bits/stdc++.h>
#define io cin.tie(NULL), ios_base::sync_with_stdio(false)
using namespace std;
using ll = long long;

int main() {
    io;
    int n, T; cin >> n >> T;
    int GCD = 0;
    vector<int> v(n);
    for (int i=0; i<n; ++i) {
        cin >> v[i];
        GCD = __gcd(GCD, v[i]);
    }
    // cout << GCD << '\n';
    if (T % GCD == 0) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}